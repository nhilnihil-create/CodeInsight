#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
string solve(){
    string s;
    cin>>s;
    ll sm=0;
    for(char c:s) sm+=(c-'0');
    return (sm%9)?"No":"Yes";   
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
