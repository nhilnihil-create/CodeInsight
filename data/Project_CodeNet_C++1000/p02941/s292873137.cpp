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

int main()
{
    sync;
    cin>>n;
    REP(i,0,n-1)
        cin>>arr[i];
    REP(i,0,n-1)
        cin>>brr[i];
    queue<int> qq;
    REP(i,0,n-1)
        qq.push(i);
    while(!qq.empty())
    {
        int id=qq.front();
        qq.pop();
        int r=(id+1)%n;
        int l=(id-1+n)%n;
        ll tot=(brr[l]+brr[r]);
        ll used=max(0ll,(brr[id]-arr[id])/tot);
        ans+=used;
        brr[id]-=used*tot;
        if(used)
        {
            qq.push(l);
            qq.push(r);
        }
    }
    REP(i,0,n-1)
    {
        //cout<<arr[i]<<" "<<brr[i]<<endl;
        if(arr[i]!=brr[i])
            ans=-1;
    }
    cout<<ans<<endl;
}
/*
3
RRRGGGBBB
*/