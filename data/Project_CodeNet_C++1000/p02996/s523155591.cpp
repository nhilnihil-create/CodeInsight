#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    int N; cin >> N;
    vector<pair<int, int>> ba(N);
    for (int i = 0; i < N; i++) {
        cin >> ba.at(i).second >> ba.at(i).first;
    }
    sort(ba.begin(), ba.end());
    ll now = 0;
    string ans = "Yes";
    for (int i = 0; i < N; i++) {
        now += ba.at(i).second;
        if (now > ba.at(i).first) {
            ans = "No";
            break;
        } 
    }
    cout << ans << endl;
    return 0;
}
