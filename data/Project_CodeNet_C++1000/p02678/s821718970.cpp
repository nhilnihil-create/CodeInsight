/*input
6 9
3 4
6 1
2 4
5 3
4 6
1 5
6 2
4 5
5 6
*/
#include<bits/stdc++.h>
#include<algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define is insert
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define mp make_pair
#define mh make_heap
#define F first
#define S second
//#define fin cin
//#define fout cout
#define file ifstream fin("input.txt");ofstream fout("output.txt");
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(n) for(long long i=0;i<n;i++)
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long int ll;
typedef long double ld;
#define lb lower_bound
#define ub uper_bound
#define bs lower_bound
//#define db(i) cout<<i<<endl;
typedef pair<ll,ll> pairs;
typedef vector<ll> vi;
typedef vector<pairs> vpair;

vi v[500000];
bool vis[500000];
void solve()
{   
    ll n,m,a,b;
    cin>>n>>m;
    fr(m)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    ll ans[n+1]={0};
    ans[1]=1;

    queue<int>q;
    q.push(1);vis[1]=1;
    while(!q.empty())
    {
        ll a=q.front();
        q.pop();
        //if(vis[a])continue;
        //vis[a]=1;
        for(int i=0;i<v[a].size();i++)
        {
            ll ch=v[a][i];
            if(!vis[ch])
            {
                vis[ch]=1;
                ans[ch]=a;
                q.push(ch);
            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(ans[j]==0)
        {
            cout<<"No"<<endl;
            return ;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
}
int main()
{
    fast;
    solve();
}