#include<bits/stdc++.h>
#define mod 1000000007
#define int long long int
#define phi 1.6180339
#define rep(i,n) for(auto i=0;i<(n);i++)
#define endl "\n"
#define For(i,a,b) for(auto i=(a);i<(b);i++)
#define op1 cin.tie(NULL)
#define op2 cout.tie(NULL)
#define op3 std::ios_base::sync_with_stdio(false)
#define MAXX 1000001
using namespace std;
vector<int> arr(MAXX);
void trozen()
{
    int n;
    cin>>n;
    vector<int> v1(n);
    for(auto &i:v1) cin>>i;
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int s1=0,s2=0;
        for(int k=0;k<=i;k++)
            s1+=v1[k];
        for(int k=i+1;k<n;k++)
            s2+=v1[k];
        ans=min(ans,abs(s1-s2));
    }
    cout<<ans<<endl;
}
int32_t main()
{
    op1;op2;op3;
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    trozen();
    return 0;
}
