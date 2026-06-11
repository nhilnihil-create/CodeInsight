#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    ll a, b;
    cin >> a >> b;
    map<ll, ll> a_factors, b_factors;
    for(int i = 2; i <= sqrt(a); i++) {
        while(a % i == 0) {
            a_factors[i]++;
            a /= i;
        }
        if(a == 1) break;
    }
    if(a != 1) a_factors[a]++;

    for(int i = 2; i <= sqrt(b); i++) {
        while(b % i == 0) {
            b_factors[i]++;
            b /= i;
        }
        if(b == 1) break;
    }
    if(b != 1) b_factors[b]++;

    
    ll ans = 1;
    for(auto x : a_factors) {
        if(b_factors.count(x.first)) ans++; 
    }
    
    cout << ans << endl;

    return 0;
}