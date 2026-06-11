#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string a;
    cin>>a;
    int ans=0;
    for(auto i : a)
    {
        ans+=i-'0';
    }
    if(ans%9==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}