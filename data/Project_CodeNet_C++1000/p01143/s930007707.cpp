#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, p, x;

    while(cin >> n >> m >> p, n | m | p) {

        int sum = 0;
        int hit = 0;

        for(int i = 1; i <= n; ++i) {
            cin >> x;
            sum += 100 * x;
            if(i == m) hit = x;
        }

        cout << (hit ? (sum * (100 - p) / 100) / hit : 0) << endl;

    }

}