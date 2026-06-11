#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pis pair<ll,string>
#define F first
#define S second
#define LCM(a,b) ((a*b)/__gcd(a,b))
#define inf 1e15
#define test ll cse;cin>>cse;for(ll _i=1;_i<=cse;_i++)
#define PI 3.14159265
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double EPS = 1E-9;
typedef vector< vector<double> > matrix;
typedef vector<int> vi;



int main() {
    fast;

    ll a, v;
    ll b, w;
    ll t;

    cin >> a >> v;
    cin >> b >> w;
    cin >> t;


    if(v <= w) cout << "NO\n";
    else {
        if((abs(a-b)+(v-w)-1)/(v-w) <= t) cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}