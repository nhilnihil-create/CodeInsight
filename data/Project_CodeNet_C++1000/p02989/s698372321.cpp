#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int main() {
    int N; cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        cin >> d.at(i);
    }
    sort(d.begin(), d.end());
    int left = N / 2 - 1, right = left + 1;
    int ans;
    if (d.at(left) == d.at(right)) {
        ans = 0;
    }
    else {
        ans = d.at(right) - d.at(left);
    }
    cout << ans << endl;
    return 0;
}