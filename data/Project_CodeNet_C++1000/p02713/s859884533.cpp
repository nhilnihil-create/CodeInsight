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
#define mod 998244353
#define inf 1e18 
 
using namespace std;
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
    IOS;
    int l;
    cin>>l;
    int sum=0,i,j,k;
    for(i=1;i<=l;i++)
    {
        for(j=1;j<=l;j++)
        {
            for(k=1;k<=l;k++)
            {
                sum+=gcd(i,gcd(j,k));
            }
        }
    }
    cout<<sum;
}