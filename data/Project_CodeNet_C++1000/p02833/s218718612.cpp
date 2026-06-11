#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
    int n;
    cin>>n;
    if(n&1)cout<<0<<"\n";
    else{
        int res=0;
        int tmp=10;
        while(tmp<=n)
        {
            res+=n/tmp;
            tmp*=5;
        }
        cout<<res<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    //cin>>_;
    for(int __=0;__<_;__++)
    {
        Digvijay();
    }
}