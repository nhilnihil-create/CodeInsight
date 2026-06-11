
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s1, s2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    int Cnt = 0;
    for (int i = 0; i < 3; ++i) {
        if (s1[i] == s2[i])
            ++Cnt;
    }
    cout << Cnt << endl;

    return 0;
}

