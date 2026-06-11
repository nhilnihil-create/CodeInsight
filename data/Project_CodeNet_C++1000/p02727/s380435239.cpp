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
    int x,y,a,b,c,i;
    cin>>x>>y>>a>>b>>c;
    vi A(a),B(b),C(c);
    for(i=0;i<a;i++) cin>>A[i];
    for(i=0;i<b;i++) cin>>B[i];
    for(i=0;i<c;i++) cin>>C[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(i=a-1;i>=a-x;i--) C.pb(A[i]);
    for(i=b-1;i>=b-y;i--) C.pb(B[i]);
    sort(C.begin(),C.end());
    int n=C.size();
    int ans=0;
    for(i=n-1;i>=n-(x+y);i--) ans+=C[i];
        cout<<ans;
}