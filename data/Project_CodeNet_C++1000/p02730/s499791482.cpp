#include <bits/stdc++.h>
using namespace std;
int main(){
	string S;
	cin >> S;
	string ans = "Yes";
	int N = (int)S.length();
	for(int i=0;i<N / 2;i++){
		if(S[i] != S[N - 1 - i])ans = "No";
	}
	string a = S.substr(0, (N - 1) / 2);
	string b = S.substr((N + 3) / 2 - 1);
	int Na = (int)a.length();
	for(int i=0;i<Na / 2;i++){
		if(a[i] != a[Na - 1 - i])ans = "No";
	}
	int Nb = (int)b.length();
	for(int i=0;i<Nb / 2;i++){
		if(b[i] != b[Nb - 1 - i])ans = "No";
	}
	cout << ans << endl;
}
