#include <bits/stdc++.h>
using namespace std;
long long const MX = 2e5 + 2, MOD = 1e9 + 7;

int main()
{
    int t= 1;
//    cin>>t;
    while(t--){
        long long a, b, c, d;
        cin>>a>>b>>c>>d;
        long long x = a*c*1ll, y = b*d*1ll, z = 1ll*a*d, u = 1ll*b*c;
        //cout<<x<<" "<<y<<" "<<z<<" "<<u<<"\n";
        cout<<max(x, max(y, max(z, u)));
    }
}


