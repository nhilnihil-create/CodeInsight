#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
using namespace std;

ll n,k;
int main() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>n>>k;
    vector<ll> p(n);
    vector<ll> c(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        --p[i];
    }
    for(int i=0;i<n;i++) cin>>c[i];
    ll maxv=-10000000000000000;
    for(int i=0;i<n;i++){
        int iter=i;
        ll seq_sum=0;
        ll seq_cnt=0;
        while(true){
            ++seq_cnt;
            seq_sum+=c[iter];
            iter=p[iter];
            if(iter==i) break;
        }
        ll one=0;
        ll cnt=0;
        while(true){
            cnt++;
            one+=c[iter];
            if(cnt>k) break;
            ll num=(k-cnt)/seq_cnt;
            ll score=one+max(0ll,seq_sum) * num;
            maxv=max(maxv,score);
            iter=p[iter];
            if(iter==i) break;
        }
    }
    cout<<maxv;
    return 0;
}


