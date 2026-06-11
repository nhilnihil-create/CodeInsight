#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(3, 0);
    for(int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i != j) {
                if(v[i] == v[j]) ans++;
            }
        }
    }

    // cout << ans << endl;
    if(ans == 2) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}