#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	string s; cin>>s;
	bool ok=true;
	if(s.size()%2==1){
		ok=false;
	}
	rep(i,0,s.size()){
		if(i%2==0){
			if(s[i]!='h'){
				ok=false;
			}
		}else{
			if(s[i]!='i'){
				ok=false;
			}
		}
	}
	if(ok) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}