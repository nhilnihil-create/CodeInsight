#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
using namespace std;
const int mod=1e9+7;

string solve(){
    int d,t,s;
    cin>>d>>t>>s;
    return (s*t >= d)?"Yes":"No";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
