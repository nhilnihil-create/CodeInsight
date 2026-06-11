#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
using namespace std;
#define N (1000000000+7)
#define M 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 
ll A(ll x){
    if(x>=0)return x;
    else return -x;
}
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}



int main(void){
	ll n,k;
	cin>>n>>k;
	vector<ll>s(n+1),a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	s[0]=0;
	for(int i=0;i<n;i++)s[i+1]=s[i]+a[i];
	map<ll,vector<ll>>r;
	r[0].push_back(0);
	for(ll i=1;i<=n;i++){
		r[(s[i]-i)%k].push_back(i);
	}
	ll ans = 0;
	for(auto itr = r.begin();itr!=r.end();++itr){
		ll amari = itr->first;
		for(ll i=0;i<r[amari].size();i++){
			ll index1 = i;
			ll pos = r[amari][i];
			auto itr = lower_bound(r[amari].begin()+i,r[amari].end(),pos+k);
			ll index2 = itr-(r[amari].begin());
			index2--;
			//cout<<amari<<" "<<r[amari][index1]<<" "<<r[amari][index2]<<endl;
			ans+=index2-index1;
		}
	}
	cout<<ans<<endl;
    return 0;
}