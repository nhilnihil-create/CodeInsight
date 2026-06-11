#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    for (int i = n; i >= 1; i--) {
        int start = 1;
        ll sum = 0;
        while (i * start <= n) {
            sum += ans[i * start];
            start++;
        }
        if (sum % 2 != a[i]) {
            ans[i] = 1 ;
        }
    }
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            vec.push_back(i);
        }
    }
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}