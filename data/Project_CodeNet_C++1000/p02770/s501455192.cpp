#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
typedef long long LL;

int d[5005];

void run_case() {
    int k, q;
    cin >> k >> q;
    for(int i = 0; i < k; ++i) cin >> d[i];
    while(q--) {
        int n, x, m;
        cin >> n >> x >> m;
        x %= m;
        LL sum = 0, zero = 0;
        for(int i = 0; i < k; ++i) {
            sum += (d[i] % m);
            zero += (d[i] % m == 0);
        }
        LL large = 1LL*((n-1)/k)*sum;
        zero = zero*((n-1)/k);
        for(int i = 0; i < n-1-((n-1)/k)*k; ++i) {
            large += (d[i] % m);
            zero += (d[i] % m == 0);
        }
        cout << n-1-(large+x)/m-zero << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(10);
    run_case();
    cout.flush();
    return 0;
}
