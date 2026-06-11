#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	string s;ll k;cin>>s>>k;
	ll cnt1=0,cnt2=0,l=s.size();
	if(s==string(l,s[0])){
		cout<<l*k/2<<"\n";
		return 0;
	}

	string ss=s+s;
	rep(i,l-1){
		if(s[i]==s[i+1]){
		s[i+1]='/';
		cnt1++;
		}
	}
	rep(i,2*l-1){
		if(ss[i]==ss[i+1]){
			ss[i+1]='/';
			cnt2++;
		}
	}
	//cout<<cnt1<<" "<<cnt2<<"\n";
	cout<<cnt1+(cnt2-cnt1)*(k-1)<<"\n";
}
