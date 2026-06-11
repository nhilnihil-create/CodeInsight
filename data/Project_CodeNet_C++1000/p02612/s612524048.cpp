#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    int ans=(1000-n%1000)%1000;

    cout<<ans<<"\n";

    return 0;
}
