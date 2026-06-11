#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    int ans = 1;
    int counter = 0;
    for(int i = 0; i < n; i++) {
        counter += l[i];
        if(counter <= x ) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}