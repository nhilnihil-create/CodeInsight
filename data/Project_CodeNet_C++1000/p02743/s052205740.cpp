#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;
typedef pair<ll,ll> Pl;
typedef vector<ll> vl;
typedef vector<Pl> vpl;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b <= 0) return -1;
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}


int main() {
    ll a,b,c;
    cin >> a>>b>>c;

    if(4*a*b < (c-a-b)*(c-a-b) && c-a-b > 0) cout << "Yes";
    else cout << "No";
    
    //std::cout << ans;
    //printf("%.8lf", ans);
    cout << "\n";
    return 0;
}
