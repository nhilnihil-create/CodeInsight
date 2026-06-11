#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define erep(i, n) for (int i = 0; i <= (n); i++)
#define erep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;

int main() {
    int x, y;
    cin >> x >> y;
    string s = "No";
    erep(turu, 100) {
        erep(kame, 100) {
            if (turu + kame == x) {
                if (turu * 2 + kame * 4 == y) {
                    s = "Yes";
                }
            }
        }
    }
    cout << s << endl;
}