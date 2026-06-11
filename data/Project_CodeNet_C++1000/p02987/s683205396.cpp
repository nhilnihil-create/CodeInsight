#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	bool ok = false;
	if(S[0]==S[1]&&S[2]==S[3]) ok = true;
	if(S[0]==S[2]&&S[1]==S[3]) ok = true;
	if(S[0]==S[3]&&S[2]==S[1]) ok = true;
	if(S[0]==S[1]&&S[1]==S[2]&&S[2]==S[3]) ok = false;
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}










