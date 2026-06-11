#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    cout<<min((n+h-1)/h,(n+w-1)/w);
    return 0;
}
