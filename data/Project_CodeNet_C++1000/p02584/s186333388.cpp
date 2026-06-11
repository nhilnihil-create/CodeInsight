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

ll x,k,d;
int main() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>x>>k>>d;
    x=abs(x);
    ll need=x/d;
    if(need>=k) cout<<x-(k*d);
    else{
        ll remain=x%d;
        k-=need;
        if(k%2==0) cout<<remain;
        else cout<<abs(remain-d);
    }
    return 0;
}


