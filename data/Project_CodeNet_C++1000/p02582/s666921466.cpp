#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;


ll solve(){
    string s;
    cin>>s;
    if(s == "RRR") return 3;
    if(s == "RRS" || s=="SRR") return 2;
    if(s == "SSS") return 0;
    return 1;
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
