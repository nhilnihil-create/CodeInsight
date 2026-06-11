#include<bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define mp  make_pair
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define inf 1e18
 
 
using namespace std;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
    IOS;
    int n,i;
    cin>>n;
    vi a(n),b(n);
    for(i=0;i<n;i++) cin>>a[i]>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2==1) cout<<b[n/2]-a[n/2]+1<<endl;
    else
    {
        int p,q,r,s;
        p=a[n/2-1];
        q=b[n/2-1];
        r=a[n/2];
        s=b[n/2];
        cout<<q+s-r-p+1;
    }
}