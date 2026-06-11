#include<bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define pb(z) push_back(z)
#define ff first
#define ss second
#define pi(a,b) make_pair(a,b)
#define pii pair<ll,ll>
#define T int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define debug(vec) cout<<(#vec)<<" : [ "; for (auto& i: vec) cout<<i<<" "; cout<< "]" << endl
#define input(v,n) vector<int>v;for(int i=0;i<n;i++){int x;cin>>x;v.push_back(x);}
#define debugg(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


const int inf    = 0x3f3f3f3f;
const ll LL_INF  = 0x3f3f3f3f3f3f3f3f;
const double PI  = acos(-1);
const double eps = 1e-4;
const int mod    = 1e9+7;
const int mx     = 2e5+5;
//vector<int>v;
//for(int i=0; i<n; i++)
//{
//    int x;
//    cin>>x;
//    v.push_back(x);
//}


int main()
{
    IOS
    vector<int>a,b,c;
    map<int,int>mp;
    int n,k;
    cin>>n;
    int cnt1=0,cnt2=0;
    rep(i,0,n)
    {
        int t,x,y;
        cin>>t;
        a.pb(t);
    }
    rep(i,0,n)
    {
        int t,x,y;
        cin>>t;
        b.pb(t);
    }
    rep(i,0,n-1)
    {
        int t,x,y;
        cin>>t;
        c.pb(t);
    }
    int tmp=-2,sum=0;
    rep(i,0,n)
    {
        sum+=b[a[i]-1];
        if(tmp+1==a[i])
            sum+=c[tmp-1];
        tmp=a[i];
    }
    cout<<sum<<endl;

}

