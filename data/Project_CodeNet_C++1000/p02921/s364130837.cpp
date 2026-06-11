#include <bits/stdc++.h>
#define int             long long
#define ld              long double
#define rep0(i,n)       for(int i=0;i<n;i++)
#define rep1(i,n)       for(int i=1;i<=n;i++)
#define rep(i,x,y)      for(int i=x;i<=y;i++)
#define reprev1(i,n)    for(int i=n;i>0;i--)
#define reprev0(i,n)    for(int i=n-1;i>=0;i--)
#define reprev(i,x,y)   for(int i=x;i>=y;i--)
#define all(c)          c.begin(),c.end()
#define rall(c)         c.rbegin(),c.rend()
#define si              set<int>
#define vi              vector<int>
#define mii             map<int,int>
#define pii             pair<int,int>
#define usi             unordered_set<int>
#define umii            unordered_map<int,int>
#define pqmx            priority_queue<int>
#define pqmn            priority_queue<int,vi,greater<int> >
#define sp(x,y)         fixed<<setprecision(y)<<x
#define setbits(x)      __builtin_popcount(x)
#define zerobits(x)     __builtin_ctz(x)
#define in(a,n)         vi a(n);rep0(i,n)cin>>a[i];
#define in1(a,n)        vi a(n+1);rep1(i,n)cin>>a[i];
#define w(t)            int t;cin>>t;while(t--)
#define endl            '\n'
#define mod             1000000007
#define M               (int)1e6+6
#define inf             1e18
using namespace std;

int n,m,k,x,y,z,a1,b,c,d,i,j;





void sol()
{   string s,t;
    cin>>s>>t;
    c=0;
    rep0(i,3)if(s[i]==t[i])c++;
    
    
    
    
    cout<<  c<<endl;
}





int32_t main(){

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // w(t)
    sol();
    return 0;
}

