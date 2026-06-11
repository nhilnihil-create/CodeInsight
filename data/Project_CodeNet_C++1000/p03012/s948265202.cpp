#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;

    vector<int> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    int s1 = 0, s2, goal = sum / 2;
    int i = 0;

    while(1) {
        s1 += w[i];
        if(s1 > goal) {
            s2 = s1 - w[i];
            break;
        }
        i++;
    }
    int ans = min(abs(2 * s1 - sum), abs(2 * s2 - sum));
    cout << ans << endl;
}