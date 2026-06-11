#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fill(x,v) memset(x,v,sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x <<": " << x << endl

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef long double C;

vi a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    a.resize(n+1);
    rep(i,0,n+1){
        cin >> a[i];
    }
    ll rpta = 0;
    ll b,aux;
    rep(i,0,n){
        cin >> b;
        aux = min(a[i], b);
        b-=aux;
        rpta+=aux;
        aux = min(a[i+1], b);
        a[i+1]-=aux;
        rpta+=aux;
    }
    cout << rpta << endl;
    return 0;
}