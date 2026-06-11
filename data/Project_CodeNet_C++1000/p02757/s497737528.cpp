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
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
int power(int a,int n,int p)
{
    a %= p;
    if(n == 1)return a;
    if(n == 0)return 1;
    if(n%2)return (a*(power((a*a)%p,n/2,p)%p))%p;
    return power((a*a)%p,n/2,p)%p;
}
const int inf = (int) 1e18;
 
int inverse(int x){
    return power(x,mod-2,mod)%mod;//little fermat....
}

void solve(){
    int n,p,ans = 0;
    string s;
    cin >> n >> p >> s;
    if(p == 2 || p == 5){
        FOR(i,0,n){
            if((s[i]-'0')%p)continue;
            ans += i+1;
        }
    }
    else {
        vector<int>cnt(100005);
        cnt[0] = 1;
        int suff = 0;
        RFOR(i,n-1,-1){
            int d = (s[i]-'0')%p;
            int tmp = (((power(10,n-1-i,p)*d)%p)+suff)%p;
            ans += cnt[tmp];
            cnt[tmp]++;
            suff = tmp%p;
        }
    }
    cout << ans << "\n";
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
