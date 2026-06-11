#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vlli vector<ll>
#define vi vector<int>
#define vs vector<string>
#define vplli vector< pair< ll,ll> >
#define plli pair< ll,ll >
#define vps vector< pair< string, string> >
#define vpi vector< pair< int, int> >
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn(i,a,n) for(ll i=a;i<n;i++)
#define scan(arr,a,n) for(ll i=(a);i<(n);i++)cin>>(arr)[i];
#define print(arr,a,n) for(ll i=(a);i<(n);i++)cout<<(arr)[i]<<" ";

ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}

long double cald(plli x, plli y){
    return sqrt(pow(abs(x.F - y.F), 2) + pow(abs(x.S - y.S), 2));
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    long double n;
    long double sum = 0;
    cin>>n;
    string s = "";
    forn(i, 0, n){
        s+=char('0'+i);
    }
    long double a[(ll)n][(ll)n];
    long double x, y;
    vector< pair< long double, long double> > v;
    forn(i, 0, n){
        cin>>x>>y;
        v.pb(mp(x, y));

    }
    forn(i, 0, n){
        forn(j, i+1, n){
            a[i][j] = cald(v[i], v[j]);
            a[j][i] = a[i][j];
        }
    }
    long double tot = 0;
    do{
        tot++;
        forn(i, 1, n){
            sum = sum+a[(ll)(s[i] - '0')][(ll)(s[i-1] - '0')];
        }
    }while(next_permutation(all(s)));
    cout<< fixed << setprecision(10) << sum/tot<<endl;
}