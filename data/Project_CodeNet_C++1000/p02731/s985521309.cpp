// I'm a f*cking looser
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fasino ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
#define input(A) for(auto &i:A) cin>>i;
signed main()
{
    fasino
    double n;
    cin>>n;
    long double k = n/3;
    cout<<fixed<<setprecision(7)<<k*k*k;
    return 0;
}