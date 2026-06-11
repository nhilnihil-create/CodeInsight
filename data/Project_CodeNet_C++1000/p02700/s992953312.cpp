#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;


string solve() {
    int h1, s1, h2, s2; cin >> h1 >> s1 >> h2 >> s2;
    int player = 0;
    while (true) {
        if (player == 0) h2 -= s1;
        else h1 -= s2;

        if (h1 <= 0 || h2 <= 0) break;
        
        player ^= 1;
    }
    
    return (h2 <= 0) ? "Yes" : "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
