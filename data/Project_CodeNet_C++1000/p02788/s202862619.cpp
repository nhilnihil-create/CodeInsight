#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int INF = 0x3f3f3f3f;
const ll  LINF = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 2e5+10;
const int mod = 1e9+7;

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,d,a,ans=0;

    cin >> n >> d >> a;

    vector<pair<ll,ll>> vs(n);
    queue<pair<ll,ll>> pq;

    for(auto &x:vs){ 
    	cin >> x.ff >> x.ss;
    }

   	sort(all(vs));

   	ll s=0;

   	for(int i=0;i<n;++i){
   		while(!pq.empty() && pq.front().ff < vs[i].ff){
   			s-=pq.front().ss;
   			pq.pop();
   		}
   		vs[i].ss=max(0LL,vs[i].ss-s);
   		ll k = (vs[i].ss+a-1)/a;
   		ans+=k;
   		s+=a*k;
   		pq.push({vs[i].ff+2*d,a*k});
   	}

    cout << ans << endl;

    return 0;
}

