#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf (1 << 21)
#define mod 1000000007

int main() {
    string S; cin >> S;
    int s = S.size();
    vector<int> ans(s);
    int r = 0;
    for (int i = 1; i < s; i++) {
        if (S.at(i) == 'L') {
            int dist = i - r;
            if (dist % 2 == 0) {
                ans.at(r)++;
            }
            else {
                ans.at(r + 1)++;
            }
        }
        else {
            r = i;
        }
    }
    int l = s - 1;
    for (int i = s - 2; i >= 0; i--) {
        if (S.at(i) == 'R') {
            int dist = l - i;
            if (dist % 2 == 0) {
                ans.at(l)++;
            }
            else {
                ans.at(l - 1)++;
            }
        }
        else {
            l = i;
        }
    }
    for (int i = 0; i < s; i++) {
        if (i != s - 1) {
            cout << ans.at(i) << ' ';
        }
        else {
            cout << ans.at(i) << endl;
        }
    }
    return 0;
}
