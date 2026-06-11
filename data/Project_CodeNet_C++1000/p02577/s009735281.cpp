#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
	string s; cin>>s;
	int sum = 0;
	for(int i=0; i<s.length(); i++) sum += s[i]-'0';
	if(sum%9==0) cout<<"Yes";
	else cout<<"No";
}

