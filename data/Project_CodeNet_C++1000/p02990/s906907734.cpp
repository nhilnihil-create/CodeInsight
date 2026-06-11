//fast code to find the ncr % MOD
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long int
#define ld long double
#define f(t) for(ll i =0;i<t;i++)
#define vi vector<int>
#define vl vector<ll>
#define pri pair<int,int>
#define mpi map<int,int>
#define prl pair<ll,ll>
#define mp make_pair
#define mpl map<ll,ll>
#define umpl unordered_map<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define inf 2e18
#define EPS 1e-3
#define PI 3.1415926535897932385
const double h = 1e-6;
const int MAX_  = 200005;
ll fac[MAX_];
ll inv[MAX_];
ll facinv[MAX_];

inline ll mul(ll a,ll b){ if(a>=MOD)a=a%MOD;if(b>=MOD)b=b%MOD;if(a*b>=MOD)return(a*b)%MOD;return(a*b);}
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > MOD) c -= MOD; return c; }
 //////////////////////*********CODE***********/////////////////////
 //////////////////////////////////////////////////////////////////
void furious()
{
    fac[1] = 1;fac[0] = 1;
    inv[0] = inv[1] =1 ;
    facinv[0]= facinv[1] = 1;
    for(int i =2;i<MAX_;i++)
    {
        fac[i] = (i*fac[i-1])%MOD;
        inv[i] = (inv[MOD % i] * (MOD - MOD/i))%MOD;
         facinv[i] = (inv[i] * facinv[i-1])%MOD;
    }
}

ll ncrm(ll n, ll r){
   if(n==r || r==0){
       return 1;
   }
   if(n<r){
       return 0;
   }
   return mul(fac[n],mul(facinv[r],facinv[n-r]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    furious();
    int n,k;   cin>>n>>k;
    for(int i = 1;i<=k;i++){
        cout << mul(ncrm(n-k+1,i),ncrm(k-1,i-1))<<"\n";
    }
    return 0;
}
