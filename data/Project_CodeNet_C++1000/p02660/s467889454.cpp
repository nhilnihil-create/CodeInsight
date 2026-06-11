#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll prime_num[maxn],prime[maxn];
int dfs(int cur, int idx,int cnt,int sum)
{
    int ans=0;
    if(sum>=prime_num[idx]||cur>prime_num[idx])
    {
        if(sum==prime_num[idx])return cnt;
        else return 0;
    }
    ans=max(ans,dfs(cur+1,idx,cnt+1,sum+cur));
    ans=max(ans,dfs(cur+1,idx,cnt,sum));
    return ans;
}
int main()
{
    ll a;
    cin>>a;
    int cnt=0;
    int mid=sqrt(a+0.5);
    ll x=a;
    for(int i=2; i<=mid; i++)
    {
        if(x%i==0)
        {
            prime[++cnt]=i;
            while(x%i==0)
            {
                prime_num[cnt]++;
                x/=i;
            }
        }
    }
    if(x>1)
    {
        prime[++cnt]=x;
        prime_num[cnt]=1;
    }
    //cout<<cnt<<endl;
    int ans=0;
    for(int i=1; i<=cnt; i++)
    {
        ans+=dfs(1,i,0,0);
    }
    cout<<ans<<endl;
    return 0;
}
