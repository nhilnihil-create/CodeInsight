#include <bits/stdc++.h>
using namespace std;

// 1 2 3 4 5 6 7 8 9 10 11 12
int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    int ans = 1e9;
    for(int i = 1;i <= 100;i++){
        int count = 0;
        for(int j = 0;j < n;j++){
            count += (v[j] - i) * (v[j] - i);
        }
        ans = min(count,ans);
    }
    cout << ans << endl;
}