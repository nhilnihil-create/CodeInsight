#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0, sum1 = 0, t;
    cin >> n;
    map <string, int> a;
    vector <int> arr(n, 0);
    string str;
    for (int i = 0; i < n; ++ i) {
        cin >> str >> t;
        sum1 += t;
        a[str] = i;
        arr[i] = sum1;
    }
    cin >> str;
    cout << arr[n - 1] - arr[a[str]];

}
