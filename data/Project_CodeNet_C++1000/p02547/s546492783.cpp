#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main() {
    int N; cin >> N;
    int cnt = 0;
    int a,b;
    string ans = "No";
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a == b) cnt++;
        else cnt = 0;
        if (cnt >= 3) ans = "Yes";
    }
    cout << ans << endl;
}