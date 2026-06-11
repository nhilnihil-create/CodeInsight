#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 1e3 + 4;

int a[N * (int)1e3];

int p[N], tot;
bool isp[N];

void euler() {
    for (int i = 2; i < N; i++) {
        if (!isp[i]) {
            p[tot++] = i;
        }
        for (int j = 0; j < tot && p[j] * i < N; j++) {
            isp[p[j] * i] = true;
            if (i % p[j] == 0) break;
        }
    }
}

bool mk[N * (int)1e3];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    euler();

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ok = true;
    int g = a[0];
    for (int i = 0; i < n; i++) {
        g = __gcd(g, a[i]);
        for (int j = 0; j < tot; j++) {
            int c = 0;
            while (a[i] % p[j] == 0) {
                a[i] /= p[j];
                c++;
            }
            if (c) {
                if (mk[p[j]]) {
                    ok = false;
                    break;
                }
                mk[p[j]] = true;
                
            }
        }
        if (a[i] > 1) {
            if (mk[a[i]]) {
                ok = false;
                break;
            }
            mk[a[i]] = true;
            
        }
    }
    
    if (ok) {
        cout << "pairwise coprime\n";
    }
    else if (g == 1) {
        cout << "setwise coprime\n";
    }
    else cout << "not coprime\n";
    return 0;
}