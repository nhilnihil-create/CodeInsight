#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
string find(int n)
{
    string ans="";
    while(n>0)
    {
        ans+=n%10+'0';
        n/=10;
    }
    int cnt=ans.size();
    cnt=3-cnt;
    while(cnt--)
    {
        ans+='0';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
string str;
cin>>str;
int ans=0;
for(int i=0;i<1000;i++)
{
    string val=find(i);
    int dp[3]={};
    for(int j=0;j<n;j++)
    {
        for(int k=2;k>=0;k--)
        {
            if(val[k]==str[j])
                {
                    if(k!=0)
                        dp[k]+=dp[k-1];
                    else
                        dp[k]+=1;
                }
        }
    }
   if(dp[2])
    ans++;
}
cout<<ans<<endl;


    return 0;
}

