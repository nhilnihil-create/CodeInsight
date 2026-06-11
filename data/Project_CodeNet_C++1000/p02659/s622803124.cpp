#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char pn;
    ll nm, nx, nd, ans;
    cin>>nm>>nx>>pn>>nd;
    nx = (nx*100) + nd;
    ans = (nm*nx)/100;
    cout<<ans<<endl;


    return 0;
}
