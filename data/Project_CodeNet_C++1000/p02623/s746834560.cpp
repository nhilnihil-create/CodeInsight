#include <bits/stdc++.h>
using namespace std;
#define LL long int
#define ULL unsigned long int
#define LD long double

LL MOD = 1000000007;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    vector<int> b(m+1);

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    vector<LL> dpa(n + 1, 0);
    vector<LL> dpb(m + 1, 0);

    for(int i = 1; i <= n; ++i){
        dpa[i] = dpa[i - 1] + a[i];
    }

    for(int i = 1; i <= m; ++i){
        dpb[i] = dpb[i - 1] + b[i];
    }

    int ans = 0, bi = m;
    for(int ai = 0; ai <= n; ++ai){
        if(dpa[ai] > k){
            break;
        }

        while(bi >= 0 && dpa[ai] + dpb[bi] > k){
            bi--;
        }
        if(bi < 0){
            break;
        }

        ans = max(ans , ai + bi);
    }

    cout << ans << endl;

    return 0;
}