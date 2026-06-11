#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define gsort(x) sort(x, x+n, greater<ll>()); 
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sync2 cout<<fixed<<setprecision(10)
const ll inf=1e9+7;
#define pi 3.14159265358979323846
#define REP(i,j,n) for (int i = (int)j; i <=(int)n; i++)
#define REPD(i,n,j) for (int i = (int)n; i>=(int)j; i--)
#define all(vv) vv.begin(),vv.end()
//priority_queue <int, vector<int>, greater<int>> mnheap;

ll arr[200005],brr[200005];
ll ans=0;
int n;
void dfs(int id)
{
    ll val[3];
    REP(i,-1,1)
    {
        val[i+1]=brr[(id+i+n)%n];
    }
    ll used=val[1]/(val[0]+val[2]);
    used=min(used,(brr[id]-arr[id])/(val[0]+val[2]));
    if(used==0)
        return;
    ans+=used;
    brr[id]-=(used*(val[0]+val[2]));
    dfs((id-1+n)%n);
    dfs((id+1+n)%n);
}
int main()
{
    sync;
    cin>>n;
    REP(i,0,n-1)
        cin>>arr[i];
    REP(i,0,n-1)
        cin>>brr[i];
    for(int itr=0;itr<1;itr++)
    {
        REP(i,0,n-1)
            dfs(i);
    }
    REP(i,0,n-1)
    {
        if(arr[i]!=brr[i])
            ans=-1;
    }
    cout<<ans<<endl;
}
/*
3
RRRGGGBBB
*/