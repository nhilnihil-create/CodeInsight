#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

void makeNextLunLun(vector<int> &L){
	if(L.size()==0){
		L.push_back(1);
		return;
	}
	else if(L.size()==1){
		if(L[0] < 9){
			L[0]++;
		}
		else if(L[0] == 9){
			L[0] = 1;
			L.push_back(0);
		}
		return;
	}
	else{
		int carry = 1;
		int l = L.size();
		for(int i = l - 1; i >= 0; i--){
			if(i == l - 1){ //末尾
				if(L[i] <= L[i-1] && L[i] < 9){
					L[i]++;
					carry = 0;
					break;
				}
			}
			else if(i != 0){ //中間
				int a = L[i-1];
				int b = L[i];
				int c = L[i+1];
				if(b <= a){
					if(b < 9 && abs((b +1 - c)) <= 1){
						L[i]++;
						for(int j=i+1; j<l; j++){
							L[j] = max(0, L[j-1] - 1);
						}
						carry = 0;
						break;
					}
				}
				else if(b == a + 1){
					continue;
				}
			}
			else{ //先頭
				if(L[i] == 9){
					//桁上がりさせる
					carry = 1;
					break;
				}
				else{
					L[i]++;
					for(int j= 1; j<l; j++){
						L[j] = max(0, L[j-1]-1);
						carry = 0;
					}
				}
			}
		}
		//桁上がり
		if(carry == 1){
			L.clear();
			L.push_back(1);
			for(int i=0; i<l; i++){
				L.push_back(0);
			}
		}
	}


}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long K;
	cin >> K;

	if(K < 10){
		printf("%lld\n", K);
		return 0;
	}

	vector<int> v;
	for(int i=1; i<=K; i++){
		makeNextLunLun(v);
	}
	for(int i=0; i<v.size(); i++){
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}