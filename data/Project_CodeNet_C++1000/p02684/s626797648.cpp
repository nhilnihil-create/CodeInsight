#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long k = 0, n = 0;
    cin >> n >> k;

    vector<int> v(n + 1, 0);
    vector<int> visited(n + 1, 0);
    int king_pos = 1;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for(int i = 1; i <= min(n + 5, k); i++) {
        king_pos = v[king_pos];

        if(visited[king_pos] > 0) {
            int l = i - visited[king_pos];
            int r = (k - visited[king_pos])%l;
            for(int j = 0; j < r; j++) {
                king_pos = v[king_pos];
            }

            cout << king_pos << endl;
            return 0;
        }
        visited[king_pos] = i;
    }

    cout << king_pos << endl;


    return 0;
}