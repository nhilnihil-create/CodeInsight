#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
#define ld long double
#define f(t) for(ll i =0;i<t;i++)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define inf 4e18
#define EPS 1e-3
#define PI 3.1415926535897932385
#define display(v) f(v.size())cout << v[i]<<" "
const double h = 1e-6;
const int MAX_  = 200005;
#define all(v) v.begin(),v.end()

inline ll mul(ll a, ll b){ return (a * 1ll * b) % MOD; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }
ll sqr(ll x)
{
    return x*x;
}
 //////////////////////*********CODE***********/////////////////////
 //////////////////////////////////////////////////////////////////


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;   cin>>n>>k;
    vector<pair<int,int> >v;
    v.pb({1,2});
    for(int i=3;i<=n;i++){
        v.pb({2,i});
    }
    int mx = (n-2) + ((n-2)*(n-3))/2;
    int mn = (n-2);
    if(k > mx){
        cout << -1;
        return 0;
    }
    int rem = mx - k;

    if(rem!=0){
    for(int i =3;i<=n;i++){
        v.pb({i,1});
        rem--;
        if(rem==0)break;
        for(int j = i+1;j<=n;j++){
            v.pb({i,j});rem--;
            if(rem==0){
                break;
            }
        }
        if(rem==0)break;
    }
    }
    cout << v.size()<<"\n";
    for(int i =0;i<(int)v.size();i++){
        cout << v[i].ff << " " << v[i].ss << "\n";
    }
    

    return 0;
}
    
