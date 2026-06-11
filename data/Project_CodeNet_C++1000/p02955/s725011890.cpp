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

//約数列挙
template <class T>
vector<T> divisor(T x){
	vector<T> res;
	for(T i=1;i*i<=x;i++){
		if(x%i==0){
			res.push_back(i);
			if(i!=x/i){
				res.push_back(x/i);
			}
		}
	}
	return res;
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int sum=0;
	vector<int> a(n);
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	vector<int> ret=divisor(sum); 
	sort(begin(ret),end(ret),greater<int>());
	for(auto x:ret){
		vector<int> now;
		rep(i,n){
			int r=a[i]%x;
			if(r){
				now.push_back(r);
			}
		}
		sort(begin(now),end(now));
		int m=now.size();
		vector<int> sum(m+1,0);
		rep(i,m){
			sum[i+1]=sum[i]+now[i];
		}
		rep(i,m+1){
			if(sum[i]==x*(m-i)-(sum[m]-sum[i]) && sum[i]<=k){
				cout<<x<<endl;
				return 0;
			}
		}
	}
}