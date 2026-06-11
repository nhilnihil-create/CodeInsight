#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, k, s;
    cin >> n >> k >> s;
    int t = s == 1e9 ? s - 1 : s + 1;
    for (int i = 0; i < k; i++) {
        cout << s << ' ';
    }
    for (int i = k; i < n; i++) {
        cout << t << ' ';
    }
    cout << '\n';
    return 0;
}
