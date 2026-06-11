#include <bits/stdc++.h>
using namespace std;
#define Boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void Crack() {
	string S;
	cin >> S;
	int ans = 0;
	if(S[0]=='R' && S[1]=='R' && S[2]=='R') ans = 3;
	else if(S[0]=='R' && S[1]=='R') ans = 2;
	else if(S[1]=='R' && S[2]=='R') ans = 2;
	else if(S[0]=='R' || S[1]=='R' || S[2]=='R') ans = 1;
	else ans = 0;
	cout << ans << endl;
}

int main() {
	Boost;
    Crack();
	return 0;
}