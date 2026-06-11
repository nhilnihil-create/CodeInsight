#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	int A[262144] = {}; 
	int INF = 1145141919; 
	multiset<int> S[18]; 
	for(int i = 0; i < (1 << N); i++) cin >> A[i]; 
	sort(A, A + (1 << N), greater<int>()); 	
	for(int i = 0; i < N; i++){
		S[i].insert(A[0]); S[i].insert(INF); 
	}
	for(int i = 1; i < (1 << N); i++){
		bool ok = false; 
		for(int j = N-1; j >= 0; j--){
			auto t = S[j].upper_bound(A[i]); 
			if(*t != INF){
				S[j].erase(t); 
				for(int k = 0; k < j; k++){
					S[k].insert(A[i]); 
				}
				ok = true; 
				break; 
			}
		}
		if(!ok){
			cout << "No" << endl; return 0; 
		}
	}
	cout << "Yes" << endl; 
}