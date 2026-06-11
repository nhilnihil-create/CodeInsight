#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, K, A[200010]; 
	cin >> N >> K; 
	for(int i = 1; i <= N; i++) cin >> A[i]; 
	int S[45][200010] = {}; 
	int T = 0; 
	for(int i = 1; i <= N; i++) S[0][i] = A[i]; 
	for(int t = 1; t < 45; t++){
		int D[200010] = {}; 
		for(int i = 1; i <= N; i++){
			D[max(i - S[t-1][i], 1)] ++; 
			if(i + S[t-1][i] + 1 <= N) D[i + S[t-1][i] + 1] --; 
		}
		int mn = 1145141919; 
		for(int i = 1; i <= N; i++){
			S[t][i] = S[t][i-1] + D[i]; 
			mn = min(mn, S[t][i]); 
		}
		if(mn == N){
			T = t; break; 
		}
	}
	for(int i = 1; i <= N; i++){
		cout << S[min(K, T)][i] << " "; 
	}
	cout << endl; 
}