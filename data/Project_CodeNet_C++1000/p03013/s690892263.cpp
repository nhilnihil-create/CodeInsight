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
#define MAXX 100011
using namespace std;
//vector<int> arr(MAXX);
bool visited[MAXX];
int arr[MAXX];
int solve(int i,int n)
{
    if(i==n)
        return 1;
    if(i>n)
        return 0;
    if(arr[i]!=-1)
        return arr[i];
    int ans1=0,ans2=0;
    if(visited[i+1]) ans1=solve(i+1,n);
    if(visited[i+2]) ans2=solve(i+2,n);
    return arr[i]=(ans1%mod+ans2%mod)%mod;

}
void trozen()
{
    int n,m;
    cin>>n>>m;
    rep(i,MAXX) arr[i]=-1,visited[i]=true;
    rep(i,m){int temp;cin>>temp;visited[temp]=false;}
    int ans=solve(0,n);
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
