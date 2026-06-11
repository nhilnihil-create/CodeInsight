#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define endl '\n'
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define pf push_front
#define pob pop_back
#define pof pop_front
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

typedef pair<int,int> pi;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

int32_t main()
{
   // boost
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<3)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(n<6)
        {
            cout<<"1"<<endl;
            continue;
        }
        int dp[n+1]={0};
        dp[0]=dp[1]=dp[2]=0;
        dp[3]=dp[4]=dp[5]=1;
        dp[6]=2;

        for(int i=7;i<=n;i++)
        {
            dp[i]=1;
            for(int j=3;j<=i-3;j++)
            {
                dp[i]+=dp[j];
                dp[i]%=mod;
            }
        }

        cout<<dp[n]<<endl;
    }


    

}