#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> f(n+1, 0);
    int p, ac = 0, pen = 0;
    string s;
    for (int i = 0; i < m; i++) {
        cin >> p >> s;
        if (s == "AC" && f[p]!=-1) {
            ac++;
            pen += f[p];
            f[p] = -1;
        }
        else if (s == "WA" && f[p]!=-1) f[p]++;
    }
    printf ("%d %d\n",ac,pen);
}