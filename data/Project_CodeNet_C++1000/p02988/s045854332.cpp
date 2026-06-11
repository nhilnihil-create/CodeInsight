#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main () {
    int n;
    cin >> n;
    int p[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int count = 0;
    for (int i = 2; i <= n - 1; i++) {
        if (((p[i] < p[i - 1]) && (p[i + 1] < p[i])) || ((p[i] > p[i - 1]) && (p[i + 1] > p[i]))) {
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}