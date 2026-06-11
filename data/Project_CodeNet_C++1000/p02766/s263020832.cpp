#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

ll mod = 1e9+7;

int solve() {
    int n, k; cin >> n >> k;

    // auto get_length = [&] () {
    //     string s = "";
    //     while (n) {
    //         s = to_string(n % k) + s;
    //         n /= k;
    //     }

    //     return static_cast<int>(s.size());
    // };    

    auto get_length = [&] () {
        int cnt = 0;
        while (n) {
            cnt++;
            n /= k;
        }

        return cnt;
    };

    return get_length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
