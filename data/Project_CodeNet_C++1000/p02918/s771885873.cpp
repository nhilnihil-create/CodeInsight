#include <bits/stdc++.h>
#define MAXN 2550
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x < n and y >= 0 and y < n)
using namespace std;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, rep = 1;
    char aux, last;
    cin >> n >> k;
    vector<int> dp;

    cin >> last;

    for (int i=0; i<n-1; i++){
        cin >> aux;
        if (aux == last) rep++;
        else last = aux, dp.push_back(rep), rep = 1;
    }
    dp.push_back(rep);

    while (k--){
        if (dp.size() <= 2){
            cout << n-1 << endl;
            return 0;
        }

        int tmp = dp.back();
        dp.pop_back();
        tmp += dp.back(), dp.pop_back();
        tmp += dp.back(), dp.pop_back();
        dp.push_back(tmp);
    }
    int ans = 0;
    for (auto x: dp) ans += x-1;


    cout << ans << endl;
    return 0;
}