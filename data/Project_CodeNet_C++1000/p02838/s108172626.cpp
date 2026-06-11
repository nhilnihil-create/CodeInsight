#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007ll
using namespace std;
ll ara[300005], cnt[2];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    scanf("%lld", &ara[i]);
    ll res= 0;
    for(int i=0; i<60; i++)
    {
        cnt[0]= cnt[1]= 0;
        for(int j=0; j<n; j++)cnt[ (ara[j]&(1ll<<(i)))!=0 ]++;
        for(int j=0; j<n; j++)
        {
            cnt[ (ara[j]&(1ll<<(i)))!=0 ]--;
            res+= ((1ll<<(i))%mod)*cnt[ (ara[j]&(1ll<<(i)))==0 ];
            res%= mod;
        }
    }
    printf("%lld\n", res);
    return 0;
}
