#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9;
ll MOD=1e18;
#define ff first
#define yy second
#define endl "\n"
#define gap ' '
/*
bool comp(const pair<int,int>&p,const pair<int,int>&q)
{
    //if(p.first!=q.first)
        return (p.first<q.first);
        //return (p.second<q.second);
}
bool comp2(const pair<int,int>&p,const pair<int,int>&q)
{
    if(p.second!=q.second)
        return (p.second<q.second);
        return (p.first<q.first);
}
bool comp3(const pair<ll,pair<ll,ll> >&p,const pair<ll,pair<ll,ll> >&q)
{
    if(p.first!=q.first) return p.first<q.first;
    if(p.second.first!=q.second.first) return p.second.first<q.second.first;
    return p.second.second<q.second.second;
}
*/
long long pp(long long a,long long b)
{
    long long t=1;
    while(b)
    {
        if(b&1) t=(t*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }return t;
}bool isprime(int n)
{
    int i=2;
    if(n==1) return true;
    if(n==2) return true;
    for(;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }return true;
}
long long lcd(long long n,long long m)
{
    if(n>m) swap(m,n);
    if(m%n==0) return m;
    else
    {int p=n+n;
        while(1)
        {
            if(p%m==0) return p;
            else p=(n+p)%MOD;
        }
    }
}
  /*bitmask
int sum_of_all_subset ( vector< int > s ){
            int n = s.size() ;
            int results[ ( 1 << n ) ] ;     ( 1 << n )= 2^n

         initialize results to 0
            memset( results, 0, sizeof( results ) ) ;

         iterate through all subsets

           for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {     for each subset, O(2^n)
                 for ( int j = 0; j < n ; ++ j ) {        check membership, O(n)
                     i f ( ( i & ( 1 << j ) ) ! = 0 )     test if bit �j� is turned on in subset �i�?
                          results[i] += s [j] ;           if yes, process �j�
                     }
                 }
           }
           */
void print(ll n)
{
    ll mask=1LL<<63;
    for(ll i=0;i<64;i++)
    {
        int p=(mask&n)?1:0;
        n=n<<1;
        cout<<p;
    }
    cout<<endl;
}

//vector<int>weight(200005,0);
//vector<int>val;
//vector<int>visited(200005,WHITE);
//int mx_w;
/*
void bfs(int sr)
{
    weight[sr]=1;
    val.push_back(1);
    visited[sr]=GREY;
    queue<int> q;
    q.push(sr);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(visited[v]==GREY) continue;
            weight[v]=weight[u]+1;
            //mx_w=max(mx_w,weight[v]);
            val.push_back(weight[v]);
            visited[v]=GREY;
            q.push(v);
        }
    }
}
*/
/*bool cmp(pair<int,pair<int,int> >&p,pair<int,pair<int,int> >&q)
{
    if(p.first!=q.first) return p.first<q.first;
    if(p.first==q.first)
    {
        if(p.second.first!=q.second.first) return (p.second.first<q.second.first);
        if(p.second.first==q.second.first)
        {
           return (p.second.second<=q.second.second);
        }
        return false;
    }
}*/
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

ll INF =1000000007;

ll binomialCeff(ll n,ll k)
{
    ll c[k+1];
    memset(c,0,sizeof(c));
    c[0]=1;
    ll i,j;
    for(i=0;i<=n;i++)
    {
        for(j=min(i,k);j>0;j--)
        {
            c[j]=c[j]+c[j-1];
        }
    }
    cout<<c[k]<<endl;
    return c[k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cs=1;
    //scanf("%d",&cs);
    while(cs--)
    {
        int n,k,c;
        int i;
        string s;
        vector<int>l,r;
        cin>>n>>k>>c>>s;
        i=0;
        while(l.size()<k&&i<n)
        {
            if(s[i]=='o')
            {
                l.push_back(i);
                i+=(c+1);
            }else i++;
        }
        i=n-1;
        while(r.size()<k&&i>=0)
        {
            if(s[i]=='o')
            {
                r.push_back(i);
                i-=(c+1);
            }else i--;
        }
        reverse(r.begin(),r.end());
        int j;
        for(i=0,j=0;i<l.size()&&j<r.size();i++,j++)
        {
            if(l[i]==r[i])
            {
                cout<<l[i]+1<<endl;
            }
        }
    }
}
