#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	string S; cin >> S;
	if (S[S.size() - 1] == 's'){
		S += "es";
	}else if (S[S.size() - 1] != 's'){
		S += "s";
	}
	cout << S << "\n";

}