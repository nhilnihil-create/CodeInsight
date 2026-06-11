#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
    }
    int k = 0;
    rep(i, n) {
        if(v[i] != i + 1)
            k++;
    }
    if(k <= 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
