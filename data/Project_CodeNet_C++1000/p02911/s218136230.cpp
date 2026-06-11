#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = 3.1415926535897932;
const ll MOD = 1000000007;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> cnt(n, 0);
    rep(i, q) {
        int a;
        cin >> a;
        cnt[a - 1]++;
    }
    int need = q - k + 1;
    rep(i, n) {
        if (cnt[i] >= need) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}