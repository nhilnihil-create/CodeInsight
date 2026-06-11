#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pf printf
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define REPSZ(i,v) REP(i,SZ(v))
#define pll pair <ll, ll>

ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

ll n,m;
ll arr1[10];
ll arr[10];
bitset<10>a,b;

void print(vector <ll> &v){cout << v.size() << endl;for(int i = 0; i < v.size(); i++){pf("%lld ", v[i]);}pf("\n");}
void print(vector <pll> &v){ cout << v.size() << endl; for(int i = 0; i < v.size(); i++){pf("%lld %lld\n", v[i].first, v[i].second);}}
void print(set<ll> s){set <ll> :: iterator itr;for (itr = s.begin(); itr != s.end(); ++itr){cout << *itr << " ";}cout << endl;}
void print(double d){cout << fixed << setprecision(10) << d << endl;}

void from_file(void){ freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}

/* ------------------main section-------------! */

ll factorial(ll x) {
    ll ans = 1;
    for(int i = 2; i <= x; i++) ans *= i;
    //cout << "ok\n";
    return ans;
}


void run() {
    fastio;
    cin >> n;
    //cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        //cout << arr1[i] << " ";
    }
    //cout << "ok\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        //cout << arr[i] << " ";
    }
    //cout << "ok\n";
    ll p1 = 0,p2 = 0;
    for(int i = 0; i < n; i++)
    {
        ll x1 = arr1[i];
        a[x1] = 1;
        ll m1 = 0;
        ll f = factorial(n-i-1);
        //cout << "ok\n";
        REP(j,x1-1)
        {
            if(!(a[j+1])) m1++;
        }
        ll x2 = arr[i];
        b[x2] = 1;
        ll m2 = 0;
        REP(j,x2-1)
        {
            if(!(b[j+1])) m2++;
        }
        //cout << "ok\n";
        p1 += f*m1;
        p2 += f*m2;
    }
    //cout << p1 << " " << p2 << endl;
    cout << abs(p1-p2) << endl;
}


int main() {
    #ifndef ONLINE_JUDGE
        //from_file();
    #endif
    run();
    return 0;
}
