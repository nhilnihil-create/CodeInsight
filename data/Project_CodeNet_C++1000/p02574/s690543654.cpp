#include<bits/stdc++.h>
#define pb push_back
#define sf scanf
#define pf printf
using namespace std;
#define ll long long
const int N=1e6+9;
const ll mod=1e9+7;
const ll inf=2e10;
int prime[N],vis[N];
void seive()
{
    for(int i=1;i<N;i++) prime[i]=i;
    for(int i=2;i<N;i+=2) prime[i]=2;
    for(int i=3;i*i<N;i+=2) {
        if(prime[i] == i) {
            for(int j=i*i;j<N;j+=i) {
                if(prime[j] == j) prime[j]=i;
            }
        }
    }
}
vector<int> chk(int v)
{
    vector<int>ans;
    while (v != 1)
    {
        int p=prime[v];
        ans.push_back(p);
        while (v%p==0) v/=p;
    }
    return ans;
}
void slv()
{
    seive();
    int n;
    cin >> n;
    int a[n+3],gcd=0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        gcd=__gcd(gcd,a[i]);
    }
    bool ok=0;
    for(int i=0;i<n;i++) {
        vector<int>ans = chk(a[i]);
        for(auto x : ans)
        {
            if(vis[x]==1) ok=1;
            vis[x]=1;
        }
        if(ok) break;
    }
    if(!ok) puts("pairwise coprime");
    else {
        if(gcd == 1) puts("setwise coprime");
        else puts("not coprime");
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    t=1;
    while (t--)
    {
        slv();
    }
    return 0;
}
