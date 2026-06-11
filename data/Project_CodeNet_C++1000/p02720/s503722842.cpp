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
    int k;
    cin>>k;
    vector<int> ans;
    queue<int> Q;
    for(int i=1;i<=9;i++) ans.push_back(i),Q.push(i);
    if(k<=ans.size()){cout<<ans[k-1]<<endl;return;}
    while(true)
    {
        if(k<=ans.size()){cout<<ans[k-1]<<endl;return;}
        int ele=Q.front();
        Q.pop();
        for(int i=-1;i<=1;i++)
        {
            int ele1=ele%10;
            if((ele1+i)<0||(ele1+i)>9) continue;
            int add=(ele*10)+(ele1+i);
            ans.push_back(add);
            Q.push(add);
        }
    }
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
