#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int sum=0;
    for(auto x:s)
    {
        sum+=x-'0';
        sum%=9;
    }
    if(sum==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
