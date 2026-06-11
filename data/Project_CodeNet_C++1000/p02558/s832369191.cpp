#include <bits/stdc++.h>

#define ll          long long int
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pair<int,int>>
#define mi          map<int,int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define rep(i,a,b)  for(i=a;i<b;i++)
#define inf         INT_MAX
#define llinf       LLONG_MAX

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

using namespace std;
const int N=2e5+5;
int par[N],r[N];
int find(int a)
{
    if(par[a]<0) return a;
    else return(par[a]=find(par[a]));
}
void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)return;
    if(r[a]>r[b])
    {
        par[b]=a;
        r[a]+=r[b];
    }
    else
    {
        par[a]=b;
        r[b]+=r[a];
    }
}
void solve()
{
    int n,q,i;
    cin>>n>>q;
    rep(i,0,n+1)par[i]=-1,r[i]=1;
    while(q--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==0)merge(a,b);
        else
        {
            if(find(a)==find(b))cout<<1;
            else cout<<0;
            cout<<endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
