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

vector<ll> zalgo(string s){
  vector<ll> ret(s.size());
  ll c=0;
  FOR(i,1,s.size()){
	if(i+ret[i-c]<c+ret[c]) ret[i]=ret[i-c];
	else{
	  ll j=max(0ll,c+ret[c]-i);
	  while(i+j<s.size() && s[j]==s[i+j]) j++;
	  ret[i]=j;
	  c=i;
	}
  }
  ret[0]=s.size();
  return ret;
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	rep(i,n){
		string t=s.substr(i);
		vector<ll> ret=zalgo(t);
		rep(j,(ll)ret.size()){
			ll now=min(ret[j],j);
			chmax(ans,now);
		}
	}
	cout<<ans<<endl;
}