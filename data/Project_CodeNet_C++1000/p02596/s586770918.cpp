#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_set>
typedef long long ll;
using namespace std;
const int mod=1e9+7;

int len(ll k){
    int cnt=0;
    for(ll i=k;i;i/=10) cnt++;
    return cnt;
}

ll solve(){
    ll k,m=0,ans=1,cur=7;
    cin>>k;
    unordered_set<ll> s;
    while(1){
        while(cur < k) ans++,cur=cur*10+7;
        m=cur%k;
        if(s.count(m)) return -1;
        s.insert(m);
        if(m == 0) return ans;
        cur=m;
    }
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
