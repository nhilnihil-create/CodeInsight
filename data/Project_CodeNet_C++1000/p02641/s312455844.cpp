#include <iostream>
using namespace std;

int x, n;
bool p[128];

int main() {
    cin >> x >> n;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        p[a] = 1;
    }

    int bestDif = 2e9, ans = -1;
    for(int i = 0; i <= 101; i++)
        if(p[i] == 0 && abs(i-x) < bestDif) {
            bestDif = abs(x-i);
            ans = i;
        }
    cout << ans;
}
