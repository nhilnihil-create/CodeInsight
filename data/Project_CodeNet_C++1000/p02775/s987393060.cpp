//#pragma GCC oplmize(2)
#include <bits/stdc++.h>
#define ll long long
#define sc(x) scanf("%lld",&x)
#define scs(x) scanf("%s",x+1)
#define pr(x) printf("%lld\n",x)
#define prs(x) printf("%s\n",x)
using namespace std;
const int maxn=1e7+5;
const int mod=998244353;
const double pi=acos(-1.0);
const double eps = 1e-8;
char s[maxn];
int a[maxn],len;
ll dp[2][maxn];   //每个状态有两个选择，dp[0][i]表示支付x张10^i元货币，dp[1][i]表示支付一张10^(i+1)，找10-x张10^i元货币

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    scs(s);
    len=strlen(s+1);
    for(int i=1;i<=len;i++){
        a[i]=s[len-i+1]-'0';
    }
    dp[0][1]=a[1];
    dp[1][1]=10-a[1];
    for(int i=2;i<=len+1;i++){
        dp[0][i]=min(dp[0][i-1]+a[i],dp[1][i-1]+a[i]+1);
        dp[1][i]=min(dp[0][i-1]+10-a[i],dp[1][i-1]+10-(a[i]+1));
    }
    pr(min(dp[0][len+1],dp[1][len+1]));
    return 0;
}


// //#pragma GCC oplmize(2)    //贪心写法
// #include <bits/stdc++.h>
// #define ll long long
// #define sc(x) scanf("%lld",&x)
// #define scs(x) scanf("%s",x+1)
// #define pr(x) printf("%lld\n",x)
// #define prs(x) printf("%s\n",x)
// using namespace std;
// const int maxn=1e7+5;
// const int mod=998244353;
// const double pi=acos(-1.0);
// const double eps = 1e-8;
// char s[maxn];
// int a[maxn],len;
// ll sum;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     scs(s);
//     len=strlen(s+1);
//     for(int i=1;i<=len;i++){
//         a[i]=s[len-i+1]-'0';
//     }
//     for(int i=1;i<=len+1;i++){
//         if(a[i]==10){
//             a[i]-=10;
//             a[i+1]++;
//         }
//         if(a[i]>5){
//             sum+=(10-a[i]);
//             a[i+1]++;
//         }
//         else if(a[i]<5){
//             sum+=a[i];
//         }
//         else{
//             sum+=5;
//             if(a[i+1]>=5){
//                 a[i+1]++;
//             }
//         }
//     }
//     pr(sum);
//     return 0;
// }