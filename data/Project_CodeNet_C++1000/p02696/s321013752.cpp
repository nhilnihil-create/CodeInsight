#include <bits/stdc++.h>
#define int long long int
using namespace std;
signed main()
{
    int a,b,n;
    cin>>a>>b>>n;
    int x = min(b-1,n);
    cout<<floor((a*x)/b) - a*floor(x/b);
    return 0;
    
}
