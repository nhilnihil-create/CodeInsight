#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>

using namespace std;
typedef long long ll;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	
	// 長さで二分探索
	int min = 0;
	int max = N;
	while(max - min > 0){
		// cout << min << " " << max << endl;
		int mid = (max+min+1)/2;
		bool found = mid > 0 ? false : true;
		
		if(!found){
			string words[5000];
			for(int i = 0; i < N-mid+1; i++){
				words[i] = S.substr(i, mid);
			}
			
			for(int i = 0; i < N-mid+1; i++){
				for(int j = i+mid; j < N-mid+1; j++){
					if(words[i] == words[j]){
						found = true;
						break;
					}
				}
				if(found){
					break;
				}
			}
		}
		
		if(found){
			min = mid;
		}
		else{
			max = mid - 1;
		}
	}
	
	cout << min << endl;
	
	return 0;
}
