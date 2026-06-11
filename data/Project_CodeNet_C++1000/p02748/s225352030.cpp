#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int         long long   
#define double      long double
#define endl        "\n"
#define pb          push_back
#define PI          3.1415926535897932384626433832795l
#define F           first
#define S           second
#define mp          make_pair
#define f(i,n)      for(int i=0;i<n;i++)
#define fastio      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)      (v).begin(),(v).end()
#define sort(v)     sort((v).begin(),(v).end())
#define rall(v)     (v).rbegin(),(v).rend()
#define rsort(v)     sort((v).rbegin(),(v).rend())
#define gcd(a,b)    __gcd((a),(b))
#define minn(v)      *min_element(v.begin(), v.end());
#define maxx(v)      *max_element(v.begin(), v.end());

typedef pair<int,int> pii;  
typedef vector<int> vi;

signed main() 
{
    fastio;
    int a,b,m;
    cin>>a>>b>>m;
    vi A(a),B(b);
    f(i,a)cin>>A[i];
    f(i,b)cin>>B[i];
    int ans=1e10;
    int x=minn(B);
    int y=minn(A)
    ans=x+y;
    f(i,m)
    {
        int x,y,c;
        cin>>x>>y>>c;
        x-=1;
        y-=1;
        ans=min(ans,A[x]+B[y]-c);
    }
    cout<<ans<<endl;
}
