#include <bits/stdc++.h>
#define nl ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define pi acos(-1)

using namespace std;

int main() {
    nl // Bazzi - Paradise

    int h, a; cin >> h >> a;
    int cnt = 0;
    while (h > 0) {
        h = h-a;
        cnt++;
    }
    cout << cnt;
    return 0;
}