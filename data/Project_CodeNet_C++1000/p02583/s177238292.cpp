#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, c = 0;
	cin >> N;
	long long num[100];
	for (int i = 0; i < N; ++i){
		cin >> num[i];
	}
	for(int i = 0; i < N-2; ++i){
		for(int j = i + 1; j < N-1; ++j){
			if(num[j] != num[i]){
				for(int k = j + 1; k < N; ++k){
					if(num[k] != num[j] && num[k] != num[i]){
						if((num[i] + num[j] > num[k]) && (num[i] + num[k] > num[j]) && (num[k] + num[j] > num[i])){
			                   c++;
						}
					}
				}
			}
		}
	}
	cout << c;
}
