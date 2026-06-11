#include <iostream>
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
#define f(i,n)              for(int i=0;i<n;i++)
#define fastio              ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)              (v).begin(),(v).end()
#define rall(v)             (v).rbegin(),(v).rend()
#define gcd(a,b)            __gcd((a),(b))
#define fill(a,value)       memset(a,value,sizeof(a));
#define minn(v)             *min_element(v.begin(), v.end());
#define maxx(v)             *max_element(v.begin(), v.end());
#define print(x)            cout<<(x)<<endl;
#define sum(v)+x            accumulate(v.begin(), v.end(),x);
#define debug(x)            cout<<#x<<'='<<(x)<<endl;
#define MOD (int)(1e9 + 7)
typedef pair<int,int> pii;  
typedef vector<int> vi;

signed main() 
{
    fastio;
    cout << fixed << setprecision(12);
    string s;
    cin>>s;
    int n=(int)s.size();
    int dp[n+1][13]={ { 0 } };
    dp[0][0]=1;
    f(i,n)
    {
        f(j,10)
        {
            int cur=s[i]-'0';
            if(s[i]=='?')
            {
                cur=j;
                
            }
            f(k,13)
            {
                int rem=(k*10+cur)%13;
                dp[i+1][rem]+=dp[i][k];
                dp[i+1][rem]%=MOD;
            }
            if(s[i]!='?')break;
        }
    }
    print(dp[n][5])
    
    
    
    return 0;
}