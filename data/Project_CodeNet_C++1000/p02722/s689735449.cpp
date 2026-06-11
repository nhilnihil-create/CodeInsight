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
#define pqueue      priority_queue<int>
#define pdqueue     priority_queue< int,vector<int> ,greater< int >>
 
using namespace std;
 
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
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
    int n;
    cin >> n;
    if(n == 2){cout << "1\n";return ;}
    int cnt = 1;
    for(int i = 2;i*i <= n-1;++i){
        if((n-1)%i)continue;
        cnt++;
        if(i*i != n-1)cnt++;
    }
    cnt++;
    for(int i = 2;i*i <= n;++i){
        if(n%i)continue;
        int x = n;
        while((x%i) == 0)x /= i;
        if((x%i) == 1)cnt++;
        if(i*i == n)continue;
        x = n;
        while((x%(n/i)) == 0)x /= (n/i);
        if((x%(n/i)) == 1)cnt++;
    }
    cout << cnt << "\n";
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
//*->always take maximum as inf for safer side ...#include <bits/stdc++.h>
 
