#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 1e6 + 100;
int T;
pii a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, [&](pii aa, pii bb) {
        return aa.first + aa.second < bb.first + bb.second;
    });
    int ans = 0;
    int lst = a[1].first + a[1].second;
    for (int i = 2; i <= n; i++) {
        if (a[i].first - a[i].second >= lst) {
            lst = a[i].first + a[i].second;
        } else ans++;
    }
    cout << n - ans << endl;
    return 0;
}