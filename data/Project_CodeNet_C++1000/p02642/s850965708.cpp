#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n;
    int *a = new int[n];
    map<int, int> m;
    int M = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        M = max(M, a[i]);
    }

    vector<bool> flag(M+1, true);

    sort(a, a+n);

    for (int i = 0; i < n; i++) {
        for (int j = 2; j * a[i] <= M; j++) {
            flag[a[i]*j] = false;
        }
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        if (flag[a[i]] == false || m[a[i]] > 1)
            ans--;
    }

    cout << ans << endl;

    return 0;
}