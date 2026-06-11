#include <iostream>
#include <climits>

int main()
{
    int h,n;
    std::cin>>h>>n;
    int a[1001], b[1001], dp[10001]={0};
    for (int i=0; i<n; i++) std::cin>>a[i]>>b[i];
    for (int i=1; i<=h; i++) dp[i]=INT_MAX;
    for (int i=1; i<=h; i++)
        for (int j=0; j<n; j++)
    {
        if (i>=a[j])
            dp[i]=std::min(dp[i],dp[i-a[j]]+b[j]);
        else dp[i]=std::min(dp[i],dp[0]+b[j]);
    }
    std::cout<<dp[h];
    return 0;
}
