#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N=1e9+7;
int32_t main()
{
    IOS;
    string s;
    cin>>s;
    int sum=0;
    for(auto x:s)
    {
        sum = sum + (x-48);
    }
    if(sum%9==0)
     cout<<"Yes";
    else
     cout<<"No";
}