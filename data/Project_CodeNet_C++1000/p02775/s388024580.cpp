#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	string s;
	cin>>s;
	s='0'+s;
	reverse(begin(s),end(s));
	int n=s.size();
	vector<vector<ll>> dp(n+1,vector<ll>(2,inf));
	dp[0][0]=0;
	rep(i,n)rep(j,2){
		if(dp[i][j]==inf) continue;
		int now=s[i]-'0';
		rep(a,10){
			int ni=i+1,nj=0,na=a,nb;
			if(j){
				if(a==0){
					nj=1;
					na=9;
				}else{
					na--;
				}
			}
			if(na-now<0){
				nj=1;
				na+=10;
			}
			nb=na-now;
			chmin(dp[ni][nj],dp[i][j]+a+nb);
		}
	}
	cout<<min(dp[n][0],dp[n][1])<<endl;
}