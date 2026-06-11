#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 30001
int first[10]; //0 ~ 9
int last[10]; // 0 ~ 9
bool syutugen[10];
int main() {
    int n;
    string s;
    cin >> n >> s;
    memset(syutugen, false, sizeof(syutugen));
    for (int i = 0; i < n; i++) {
        if (!(syutugen[s[i] - '0'])) {
            first[s[i] - '0'] = i;
        }
        syutugen[s[i] - '0'] = true;
        last[s[i] - '0'] = i;
    }
    int count = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if ((syutugen[i]) && (syutugen[k]) && (syutugen[j])) {
                    bool ok = false;
                    for (int l = first[i] + 1; l <= last[k] - 1; l++) {
                        if (s[l] - '0' == j) {
                            ok = true;
                        }
                    }
                    if (ok) {
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}