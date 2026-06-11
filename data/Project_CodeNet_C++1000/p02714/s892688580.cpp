#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	string S;
	cin >> N >> S;
	long long r = 0, g = 0, b = 0;
	for(int i=0;i<N;i++){
		if(S[i] == 'R')r++;
		if(S[i] == 'G')g++;
		if(S[i] == 'B')b++;
	}
	long long ans = r * g * b;
	for(int i=0;i<N;i++){
		for(int j=1;i + 2 * j<N;j++){
			if(S[i] != S[i + j] && S[i + j] != S[i + j * 2] 
				&& S[i] != S[i + 2 * j])ans--;
		}
	}
	cout << ans << endl;
}
