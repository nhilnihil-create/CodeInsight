#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const ll mod=1e9+7;
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>ok(n+1,1);
    for(int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        ok[k]=0;
    }
    vector<ll>dp(n+1);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=min(n,i+2);j++)
        {
            if(ok[j])
            {
                dp[j]+=dp[i];
                dp[j]%=mod;
            }
        }
    }
    cout<<dp[n]<<endl;






}












































