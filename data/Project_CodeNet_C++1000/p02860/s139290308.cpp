#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
const ll MAX = 1e6 + 3;
const ll inf = 1e18;
const ll mod = 1e6 + 3;



int main(){
    fastio;
    ll n;
    string s;
    cin >> n >> s;
    if(n&1) cout << "No\n";
    else{
        string aux = s.substr(0,n/2);
        if(s == aux+aux) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}