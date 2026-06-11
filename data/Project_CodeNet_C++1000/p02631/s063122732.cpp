#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <queue>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);
void solve(){
    int n,s=0;
    cin>>n;
    int a[n];
    for(int &i:a) cin>>i;
    for(int i:a) s=s^i;
    for(int i:a) cout<<(s^i)<<' ';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    //while(t--) cout<<solve()<<'\n';
    while(t--) solve(),cout<<'\n';
    return 0;
}
