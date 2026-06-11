#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	int N; cin >> N; 
	long long A[100010] = {}; 
	long long sum = 0; long long sum2 = 0; 
	long long odd = 0; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; sum ^= A[i]; 
	}
	for(int i = 0; i < N; i++) A[i] -= (A[i] & sum); 
	int p = -1; 
	for(int d = 59; d >= 0; d--){
		if((sum >> d) & 1) continue; 
		for(int i = p + 1; i < N; i++){
			if((A[i] >> d) & 1){
				swap(A[i], A[p + 1]); 
				p++; 
				for(int j = 0; j < N; j++){
					if(j == p) continue; 
					if((A[j] >> d) & 1) A[j] ^= A[p]; 
				}
				break;  
			}
		}
	}
	for(int i = 0; i < 60; i++) sum2 ^= A[i]; 
	cout << sum + 2 * sum2 << "\n"; 
}