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
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int &i:a) cin>>i;
    int l=1,h=*max_element(a,a+n),m,ans=h;
    while(l<=h){
        m=(l+h)/2;
        int cuts=0;
        for(int i:a){
            if(m) cuts+=(i/m-(i%m==0));
            else cuts+=(2*i+1);
        }
        if(cuts <= k) ans=m,h=m-1;
        else l=m+1;
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
