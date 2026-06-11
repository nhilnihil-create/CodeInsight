#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
const ll INF = 1LL << 60;
ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(),a.end());
    int sum = 0;
    rep(i,k) sum += a[i];
    cout << sum << endl;
    return 0;
}
