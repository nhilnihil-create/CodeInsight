#include<bits/stdc++.h>

using namespace std;

#define pb            push_back
#define mp            make_pair
#define po            pop_back
#define fi            first
#define se            second
#define mxn           200005
#define ll            long long int
#define ldb           long double
#define forn(n)       for(int i=0 ; i<n ; i++)
#define all(v)        v.begin(),v.end()
#define endl          "\n"
#define deg(x)        cout<<endl<<#x<<" = "<<(x)<<endl;
#define casep(x)      cout<<"Case #"<<(x)<<": ";
#define fast          ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef pair<int,int> pp;
typedef vector<int> vi;
typedef vector<pp> vpp;
typedef vector<vi> vvi;

const ll inf = LLONG_MAX;

ll power_mod(int a, int n, int mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
ll power(ll a,ll n){if(n==0){return 1;}ll p=power(a,n/2);p = (p * p);if (n%2==1){p=(p*a);}return p;}
int gcd(int a,int b){ return __gcd(a,b);}
int lcm(int a,int b){return a*b/__gcd(a,b);}
vector<vi> adj;
bool vis[mxn];

void run(ll test){

    ll n;
    cin >> n;
    ll a[n];

    ll maxi = 0;
    forn(n){
        cin >> a[i];
        maxi = max(a[i],maxi);
    }

    vi cnt(maxi+1,0);

    bool ok = 1;
    for(int i=n-1 ; i>=0 ; i--) {
        for(int j=2 ; j<=sqrt(a[i]) ; j++) {
            if(a[i]%j == 0) {
                if(cnt[j]) ok = 0;
                cnt[j]++;
                while(a[i]%j == 0) {
                    a[i]/=j;
                }
            }
        }
        if(a[i] > 2) {
            if(cnt[a[i]])
                ok = 0;
            cnt[a[i]]++;
        }
    }

    if(ok) {
        cout << "pairwise coprime";
        return ;
    }

    ok = 1;
    forn(maxi) {
        if(cnt[i] >= n) {
            ok = 0;
            break;
        }
    }

    if(ok) {
        cout << "setwise coprime";
        return ;
    }

    cout << "not coprime";

}

int main(){

    fast;
    int t=1;
    // cin >> t;
    for(int i=1 ; i<=t ; i++){
        run(i);
        cout << endl;
    }
    return 0;
}
