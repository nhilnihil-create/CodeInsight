#include <bits/stdc++.h>
#define int long long
using namespace std;
#define _READ freopen("input.txt", "r", stdin);
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
int32_t main()
{
    int n,m;
    cin>>n;
     m=(n+1)/2;
    cout<<fixed<<setprecision(15)<<((double)m/n);
    return 0;
}