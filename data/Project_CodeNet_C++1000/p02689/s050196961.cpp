#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<bool> hy(n, true);
    int a, b;
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        if(h[a] > h[b]) {
            // if(hy[a])hy[a] = true;
            hy[b] = false;
        }
        else if(h[a] == h[b]) {
            hy[a] = false;
            hy[b] = false;
        }
        else {
            // if(!hy[b])hy[b] = true;
            hy[a] = false;
        }
    }
    int count = 0;
    rep(i, n) if(hy[i]) count++;
    cout << count << endl;
}