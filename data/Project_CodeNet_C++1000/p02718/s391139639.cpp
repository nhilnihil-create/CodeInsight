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
    double n;
    int m;
    cin>>n>>m;
    vector<double> v1(n);
    double summ=0;
    for(auto &i:v1) cin>>i,summ+=i;
    double temp=4*m;
    temp+=0.0;
    int cnt=0;
    for(auto i:v1)
    {
        if(i>=(summ/temp)) cnt++;
    }
    if(cnt>=m) cout<<"Yes"<<endl;
    else  cout<<"No"<<endl;
    
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
