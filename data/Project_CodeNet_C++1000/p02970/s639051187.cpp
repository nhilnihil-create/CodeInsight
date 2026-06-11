#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,d;
    cin>>n>>d;

    int ans=(n-1)/(d*2+1)+1;

    cout<<ans<<"\n";

    return 0;
}
