#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;

template <class _T> inline bool chmax (_T& a,_T b){if(a<b){a=b;return true;}return false;}
template <class _T> inline bool chmin (_T& a,_T b){if(a>b){a=b;return true;}return false;}

const long long INF = 1LL << 60;

bool dp[110][10100] = {false};

int main(void){
	string s;cin >> s;
	bool ok = true;
	if(s.length()%2==1)ok = false;
	for(int i=0;i<s.length();i++){
		if(i%2==0) if(s[i]!='h') ok = false; 
		if(i%2==1) if(s[i]!='i') ok = false; 
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
