#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    
    int ans = 99999999;
    for (int i = 1; i < n; i++) {
        int s1 = 0;
        for (int j = 0; j < i; j++) {
            s1 += w[j];
        }

        int s2 = 0;
        for (int j = i; j < n; j++) {
            s2 += w[j];
        }

        ans = min(ans, abs(s1-s2));
    } 

    cout << ans << endl;
}