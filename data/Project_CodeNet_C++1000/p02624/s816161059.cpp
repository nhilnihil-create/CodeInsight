#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "
int main(){
    ll n;cin>>n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        //n以下の最大のiの倍数
        ll last_term = (n/i)*i;
        ll num_term = (last_term-i)/i+1;
        ans += (i+last_term) * num_term / 2;
    }
    co(ans);
}