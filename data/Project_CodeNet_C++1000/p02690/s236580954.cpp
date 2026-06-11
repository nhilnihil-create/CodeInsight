/* You can't hack me! */
#include"bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define fo(i,n) for(ll i=0; i<(n); i++)
#define FO(i,a,b) for(auto i=a; i!=(b); i+=(b)>(a)?1:-1)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define os(x) cout<<x<<' '
#define on(x) cout<<x<<"\n"
#define nl cout<<"\n"
#define maxe(x) max_element(all(x))-(x).begin()
#define mine(x) min_element(all(x))-(x).begin()
const ll P=998244353;
const ll MaxN=2000010;
const long double pi=3.14159265358979323846264338;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\ASISH\\Desktop\\coding\\input.txt", "r", stdin);
    freopen("C:\\Users\\ASISH\\Desktop\\coding\\output.txt", "w", stdout);
#endif

    ll T=1;
    // cin>>T;
    fo(q, T)
    {
        ll X, a, b;
        cin>>X;
        for(a=0; a<=200; a++){
            for(b=-200; b<=200; b++){
                if((ll)(pow(a, 5)-pow(b, 5))==X) break;
            }
            if((ll)(pow(a, 5)-pow(b, 5))==X) break;
        }
        os(a); on(b);
    }
    cerr << "Time : " << ((double)clock()) / (double)CLOCKS_PER_SEC << "s\n";
    return 0;
}