#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
ll solve(){
    int n;
    cin>>n;
    int a[n];
    for(int &i:a) cin>>i;
    ll mx=a[0],ans=0;
    for(int i:a){
        mx=max(mx,(ll)i);
        ans+=(mx-i);
    }
    return ans;
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
