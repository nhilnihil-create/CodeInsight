#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

ll A[MAXN];
ll B[MAXN];
ll ans[MAXN];

void solve(int n,int k)
{
    if(n==1){
        for(int i=1;i<=k;i++)
            ans[i] = 1;
        return;
    }

    solve((n>>1),k);

    for(int i=1;i<=k;i++){
        A[i] = ans[i];
    }

    for(int i=1;i<=k;i++){
        for(int j=(i<<1);j<=k;j+=i){
            A[i]+=A[j];
            if(A[i]>=MOD)A[i]-=MOD;
        }
        B[i] = A[i];
    }

    for(int i=1;i<=k;i++){
        ans[i] = (A[i]*B[i])%MOD;
    }

    for(int i=k;i>=1;i--){
        for(int j=(i<<1);j<=k;j+=i){
            ans[i]+=(MOD-ans[j]);
            if(ans[i]>=MOD)ans[i]-=MOD;
        }
    }

    if(n&1){
        for(int i=1;i<=k;i++){
            A[i] = ans[i];
            B[i] = k/i;
        }

        for(int i=1;i<=k;i++){
            for(int j=(i<<1);j<=k;j+=i){
                A[i]+=A[j];
                if(A[i]>=MOD)A[i]-=MOD;
            }
        }

         for(int i=1;i<=k;i++){
            ans[i] = (A[i]*B[i])%MOD;
        }

        for(int i=k;i>=1;i--){
            for(int j=(i<<1);j<=k;j+=i){
                ans[i]+=(MOD-ans[j]);
                if(ans[i]>=MOD)ans[i]-=MOD;
            }
        }
    }

    return;
}

int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    solve(n,k);

    ll res = 0;

    for(int i=1;i<=k;i++){
        res+=(ll)i*ans[i];
    }

    res%=MOD;

    cout<<res<<"\n";

    return 0;
}
