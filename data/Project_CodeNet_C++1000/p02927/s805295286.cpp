#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int m, d;
    cin >> m >> d;
    int count = 0;
    rep(i, m) {
        rep(j, d) {
            int d10 = (j + 1) / 10;
            int d1 = (j + 1) % 10;
            if(d10 >= 2 && d1 >= 2) {
                if(i + 1 == d10 * d1) count++;
            } 
        }
    }
    cout << count << endl;
    return 0;
}