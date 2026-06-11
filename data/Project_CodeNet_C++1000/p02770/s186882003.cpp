#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int k, q, d[5005], dd[5005];
void init(){
    k = read(), q = read();
    for (int i = 0; i < k; ++i)
        d[i] = read();
}
void solve(){
    while (q--){
        int n = read(), x = read(), m = read();
        int ans = 0;
        int t1 = (n - 1) / k, t2 = (n - 1) % k;
        long long sum = x % m;

        for (int i = 0; i < k; ++i){
            int dd = d[i] % m;
            if (dd == 0){
                ans += t1;
                if (i < t2) ++ans; 
            }
            sum += 1ll * t1 * dd;
            if (i < t2) sum += dd;
        }
            
        ans += sum / m;
        ans = n - 1 - ans;
        printf("%d\n", ans);
    }
}
int main(){
    init();
    solve();
    return 0;
}