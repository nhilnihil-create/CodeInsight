#include <bits/stdc++.h>
using namespace std;
struct Child
{
    long long A,place;
    bool operator>(Child XYZ) const
    {
        return A>XYZ.A;
    }
};
long long dp[2002][2002];
int main()
{
    long long N;
    cin>>N;
    vector<Child> in(N);
    for(long long i=0;i<N;i++)
    {
        cin>>in[i].A;
        in[i].place=i;
    }
    sort(in.begin(),in.end(),greater<Child>());
    long long ans=0;
    for(long long l=0;l<N;l++)
    {
        for(long long r=0;r<N;r++)
        {
            long long tmp=l+r;
            if(l+r==N)
            {
                ans=max(ans,dp[l][r]);
                break;
            }
            dp[l+1][r]=max(dp[l][r]+abs(in[tmp].place-l)*in[tmp].A,dp[l+1][r]);
            dp[l][r+1]=max(dp[l][r]+abs(in[tmp].place-(N-1-r))*in[tmp].A,dp[l][r+1]);
        }
    }
    cout<<ans<<endl;
}