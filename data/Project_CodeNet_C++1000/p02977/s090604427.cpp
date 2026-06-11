#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
int n;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    if(__builtin_popcount(n) == 1){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    cout << "1 2\n2 3\n1 " << 3+n << "\n" << 3+n << " " << 2+n << "\n" << 2+n << " " << 1+n << "\n";
    int mx = n-1+n%2;
    for(int i=4; i<mx; i+=2){
        cout << "1 " << i << "\n" << i << " " << i+1 << "\n";
        cout << "1 " << n+i+1 << "\n" << n+i+1 << " " << n+i << "\n";
    }
    if(n % 2 == 0){
        int mx = 1;
        while(mx*2 < n) mx *= 2;
        int o = n ^ mx ^ 1;
        cout << mx << " " << n << "\n";
        cout << n+o << " " << 2*n << "\n";
    }
 
    return 0;
}