#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define fi first
#define se second
#define PI (acos(-1))

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i];if(i<len-1) s<<" ";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i]<<endl;
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){
	s<<"{ ";
	for(auto itr=v.begin();itr!=v.end();++itr) {
		if (itr!=v.begin()) {s<< ", ";}
		s<<(*itr);
	}
	s<<" }";
	return s;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){
	s<<"{"<<endl;
	for(auto itr=m.begin();itr!=m.end();++itr){
		s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;
	}
	s<<"}"<<endl;
	return s;
}

const ll mod=1e9+7;
const ll inf=1e15;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<ll> t(2),a(2),b(2),l(2);
	cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];
	l[0]=a[0]*t[0]+a[1]*t[1];
	l[1]=b[0]*t[0]+b[1]*t[1];
	ll x=a[0]*t[0],y=a[1]*t[1],z=b[0]*t[0],w=b[1]*t[1];
	if(l[0]==l[1]){
		cout<<"infinity"<<endl;
		return 0;
	}else if(l[0]<l[1]){
		ll ret=l[1]-l[0];
		if(z>=x) cout<<0<<endl;
		else{
			ll ans=(x-z+ret-1)/ret*2-1;
			if((x-z)%ret==0) ans++;
			cout<<ans<<endl;
		}
	}else{
		ll ret=l[0]-l[1];
		ll ans=0;
		if(x>=z) cout<<0<<endl;
		else{
			swap(x,z);
			ll ans=(x-z+ret-1)/ret*2-1;
			if((x-z)%ret==0) ans++;
			cout<<ans<<endl;
		}
	}
}