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
    int n;
    cin >> n;

    int f[n] = {};
    rep(i,n){
        int a; cin >> a;
        a--;
        f[a]++;
    }
    sort(f,f+n,greater<int>());
    int m = 0;
    rep(i,n){
        if(f[i] > 0)m++;
    }
    int a[m];
    rep(i,m)a[i] = f[i];
    sort(a,a+m);
    int sum[m+1] = {};
    srep(i,1,m+1){
        sum[i] = sum[i-1] + a[i-1];
    }

    ll y[n+2] = {};
    srep(i,1,n+2){
        ll x = i;
        int tmp = 0;
        int ite = lower_bound(a, a+m, x) - a;
        tmp += (ll)(m - ite) * x + sum[ite];
        y[x] = tmp / x;
    }

    drep(i,n+1){
        y[i] = max(y[i], y[i+1]);
    }

    int now = n+1;
    srep(i,1,n+1){
        while(y[now] < i){
            if(now == 0)break;
            now--;
        }
        cout << now << endl;
    }

    /*
    srep(i,1,n+1){
        ll k = i;
        int l = 0;
        int r = n + 1;
        while(l + 1 < r){
            ll x = (l + r) / 2;
            int tmp = 0;
            int ite = lower_bound(a, a+m, x) - a;
            tmp += (ll)(m - ite) * x + sum[ite];
            if(tmp >= x * k){
                l = x;
            }else{
                r = x;
            }
        }
        cout << l << endl;
    }
    */

    return 0;
}
 
 
