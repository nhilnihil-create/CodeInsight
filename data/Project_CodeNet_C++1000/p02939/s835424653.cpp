/*
 * @Author: RBQRBQ
 * @Date: 2020-04-26 16:27:39
 * @LastEditors: RBQRBQ
 * @LastEditTime: 2020-04-26 16:47:48
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;ll f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
        while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
        x=x*f;
    }
}
using namespace IO;
const int maxn=200000;
char s[maxn+10];
ll dp[maxn+10][3];
inline void update(ll& x,ll y)
{
    if(x<y) x=y;
    return ;
}
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    dp[0][1]=1;
    dp[0][2]=0;
    dp[1][1]=(s[1]!=s[0])?2:1;
    dp[1][2]=1;
    for(int i=2;i<len;i++)
    {
        if(s[i]!=s[i-1]) update(dp[i][1],dp[i-1][1]+1);
        update(dp[i][1],dp[i-1][2]+1);
        update(dp[i][2],dp[i-2][1]+1);
        if(s[i]!=s[i-2]||s[i-1]!=s[i-3]&&i!=2) update(dp[i][2],dp[i-2][2]+1);
    }
    cout<<max(dp[len-1][1],dp[len][2]);
}