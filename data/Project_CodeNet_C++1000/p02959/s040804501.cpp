#include <bits/stdc++.h>
using namespace std;

int n;
long long city[110000];
long long hero[110000];
long long sum = 0;
long long tmp;

// Ci <= min(Ai + Ai+1, Bi)
int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> city[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> hero[i];
    }
    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            tmp = min(city[i], hero[i]);
            city[i] -= tmp;
            sum += tmp;
            hero[i] -= tmp;
        }
        if (i == n) {
            tmp = min(city[i], hero[i-1]);
            city[i] -= tmp;
            sum += tmp;
            break;
        }
        tmp = min(city[i], hero[i-1]);
        sum += tmp;
        city[i] -= tmp;
        tmp = min(city[i], hero[i]);
        sum += tmp;
        hero[i] -= tmp;
    }
    cout << sum << "\n";
    return 0;
}
