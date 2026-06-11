#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
using namespace std;
char a[200005];
int dp[3000];
int mod=2019;
ll sum;
int main()
{
    cin>>a;
    int n=strlen(a);
    int ans=0,y=1;
    for(int i=n-1;i>=0;i--)
    {
        ans=(ans+(a[i]-'0')*y)%mod;
        y=y*10%mod;
        dp[ans]++;
    }
    for(int i=1;i<2019;i++)
    {
        if(dp[i]>1)
        {
            sum+=(ll)dp[i]*(dp[i]-1)/2;
        }
    }
    sum+=dp[0]*(dp[0]+1)/2;
        cout<<sum<<endl;
    return 0;
}
