#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string>vst;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

void fastio(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	return;
}
#define all(ct) ct.begin() , ct.end()
#define endl "\n"
#define fr(i,a) for(auto i:a)
#define f(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define in(d,v) d.find(v)!=d.end()
#define mp make_pair
#define size(a) int(a.size())

const ll mod = 1e9 + 7;
const ll inf = ll(1e18);
const double PI = acos(-1);

ll modexp(ll x, ll n, int md) {
	if (n == 0)return 1;
	if (n % 2 == 0)return modexp((x * x) % md, n / 2, md);
	return (x * modexp((x * x) % md, n / 2, md)) % md;
}


vvl dp(2001,vl(2001,-1));
vll a(2000);
ll happy(ll l,ll r,int n){
    //cout<<l<<" "<<r<<endl;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(l==r){
        return dp[l][r]=a[n].first*abs(a[n].second-l);
    }
    dp[l][r]=happy(l+1,r,n+1)+a[n].first*abs(a[n].second-l);
    dp[l][r]=max(dp[l][r],happy(l,r-1,n+1)+a[n].first*abs(a[n].second-r));
    return dp[l][r];
}
int main() {
	fastio();
	//clock_t tm = clock();
	ll n;
    cin>>n;
    f(i,0,n){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(all(a),greater<pll>());
    cout<<happy(1,n,0)<<endl;
	//cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}
