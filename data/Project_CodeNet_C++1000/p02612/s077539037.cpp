#include <bits/stdc++.h>
using namespace std;;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int ans=1000-n%1000;
    if(ans%1000==0)
        cout<<0<<endl;
    else
        cout<<ans;
    return 0;
}
