#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int k, q;
    cin >> k >> q;
    ll d[k];
    rep(i,k)cin >> d[i];

    rep(loop,q){
        ll n, x, m;
        cin >> n >> x >> m;
        x %= m;
        ll b[k];
        ll sum = 0;
        ll zero = 0;
        rep(i,k){
            b[i] = d[i] % m;
            sum += b[i];
            if(b[i] == 0)zero++;
        }
        ll ans = n - 1;
        ll now = x;
        n--;
        now += n / k * sum;
        ll cnt = 0;
        cnt += n / k * zero;
        n -= n / k * k;
        rep(i,n){
            now += b[i];
            if(b[i] == 0)cnt++;
        }
        ans -= cnt;
        ans -= now / m;
        cout << ans << endl;
    }


    return 0;
}
 
 
