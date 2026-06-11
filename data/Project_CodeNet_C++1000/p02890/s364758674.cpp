#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
int a[300010];
int cnt[300010];
int ans[300010];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a[x] ++ ;
    }
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++;
    }
    for(int i=n;i>1;i--)
    {
        cnt[i-1] += cnt[i]; 
    }
    int Ans = 0;
    long long sum=0;
    for(int i=n;i>=1;i--)
    {
        while(sum+cnt[Ans+1]>=1ll*i*(Ans+1))
            sum+=cnt[++Ans];
        ans[i] = Ans;
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}