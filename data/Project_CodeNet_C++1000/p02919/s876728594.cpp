#include <bits/stdc++.h>
using namespace std;
const int N=100009;
typedef long long ll;
ll n,ans;
ll a[N];
ll pos[N];
ll lmaxp[N],rmaxp[N];
int main() {
    cin>>n;
    for(ll i=1;i<=n;i++) {
        cin>>a[i];
        pos[a[i]]=i;
        lmaxp[i]=i-1;
        rmaxp[i]=i+1;  
    }
    for(ll i=1;i<=n;i++) {
        ll lpos1=lmaxp[pos[i]];
        ll lpos2=lmaxp[lpos1];
        ll rpos1=rmaxp[pos[i]];
        ll rpos2=rmaxp[rpos1];
//        cout<<lpos2<<" "<<lpos1<<" "<<i<<" "<<rpos1<<" "<<rpos2<<endl;
        if(lpos1!=0) ans+=i*(lpos1-lpos2)*(rpos1-pos[i]);
        if(rpos1!=n+1) ans+=i*(pos[i]-lpos1)*(rpos2-rpos1);
        lmaxp[rpos1]=lpos1;
        rmaxp[lpos1]=rpos1;
    }
    cout<<ans<<endl;
    return 0;
}