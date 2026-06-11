#include <bits/stdc++.h>
 
#define int         long long
#define uint        unsigned int
#define ld          long double
#define showoff     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb          push_back
#define pii         pair<int,int>
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>b;--i)
#define f           first
#define se          second
#define maxn        200005
#define all(v)      v.begin(),v.end()
#define sz(x)       (int)x.size()
#define mod         1000000007
#define pqueue      priority_queue<pii>
#define pdqueue     priority_queue< int,vector<int> ,greater< int >>
 
using namespace std;
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
int power(int a,int n)
{
    a %= mod;
    if(n == 1)return a;
    if(n == 0)return 1;
    if(n%2)return (a*(power((a*a)%mod,n/2)%mod))%mod;
    return power((a*a)%mod,n/2)%mod;
}

const int inf = (int) 1e18;
 
int inverse(int x){
    return power(x,mod-2)%mod;//little fermat....
}


void solve(){
    int n,m;
    cin >> n >> m;
    set<int>pows;
    vector<int>v(n+5);
    FOR(i,1,n+1){
        cin >> v[i];
        int x = v[i],p = 0;
        while((x%2) == 0)x /= 2,p++;
        pows.insert(p);
    }
    if(sz(pows) > 1){cout << "0\n";return ;}
    FOR(i,1,n+1)v[i] /= 2;
    if(n == 1){
        cout << (m/v[1]+1)/2 << "\n";return ;
    }
    int l = (v[1]*v[2])/__gcd(v[1],v[2]);
    FOR(i,3,n+1){
        if(v[i]/__gcd(v[i],l) > ceil((1.0l*m)/(1.0l*l))){cout << "0\n";return ;}
        l = (l*v[i])/__gcd(v[i],l);
    }
    cout << (m/l+1)/2 << "\n";
}

signed main()   
{
    showoff;
    int T = 1;
    //cin >> T;
    FOR(t,1,T+1){
       solve();
    }
    return 0;
}
//*->for large size of matrix take int not long long if possible......
//*->always take maximum as inf for safer side ...
