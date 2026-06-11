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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	char s[500002] = {0};
	int L = 200001;
	int R = L;

	string S;
	long long Q;
	cin >> S;
	cin >> Q;
	strcpy(s+L, (const char*)S.c_str());
	R = L + strlen(S.c_str()) -1;
	
	int rev = 0;
	for(int i=1; i<=Q; i++){
		int t, f;
		char c;
		cin >> t;
		if(t == 1){
			rev = (rev + 1) % 2;
		}
		else if(t == 2){
			cin >> f;
			cin >> c;
			if(f == 1){
				if(rev == 0){
					s[L - 1] = c;
					L--;
				}
				else{
					s[R + 1] = c;
					R++;
				}
			}
			else if(f == 2){
				if(rev == 0){
					s[R + 1] = c;
					R++;
				}
				else{
					s[L - 1] = c;
					L--;
				}
			}
		}
	}
	if(rev == 0){
		for(int i=L; i<=R; i++){
			printf("%c", s[i]);
		}
	}
	else if(rev == 1){
		for(int i=R; i>=L; i--){
			printf("%c", s[i]);
		}
	}
	printf("\n");
	return 0;
}