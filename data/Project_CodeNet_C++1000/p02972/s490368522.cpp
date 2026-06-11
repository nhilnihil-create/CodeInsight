#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int                 long long   
#define double              long double
#define endl                "\n"
#define pb                  push_back
#define PI                  3.1415926535897932384626433832795l
#define F                   first
#define S                   second
#define mp                  make_pair
#define f(i,n)              for(int i=0;i<n;++i)
#define loop(i,a,b)         for (int i=a ; i<b ;++i)
#define fastio              ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)              (v).begin(),(v).end()
#define rall(v)             (v).rbegin(),(v).rend()
#define gcd(a,b)            __gcd((a),(b))
#define fill(a,value)       memset(a,value,sizeof(a));
#define minn(v)             *min_element(v.begin(), v.end());
#define maxx(v)             *max_element(v.begin(), v.end());
#define print(x)            cout<<(x)<<endl;
#define sum(v)+x            accumulate(v.begin(), v.end(),x);
typedef pair<int,int> pii;  
typedef vector<int> vi;

signed main() 
{
    fastio;
    cout << fixed << setprecision(12);
    int n;
    cin>>n;
    int A[202020];
    int B[202020];
    f(i,n)cin>>A[i+1];
    vi ans;
    for(int i=n;i>=1;i--)
    {
        int cur=0;
        for(int j=i;j<=n;j+=i)
        {
            cur+=B[j];
        }
        cur%=2;
        if(cur!=A[i])
        {
            ans.pb(i);
            B[i]=1;
        }
        
    }
    reverse(all(ans));
    print(ans.size())
    for(auto p:ans)
    {
        cout<<p<<" ";
    }
    
    
    
    
    
    return 0;
}