#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    map<string, int> m;
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        string key;
        cin >> key;
        m[key] = 1;
    }

    cout << m.size() << endl;
    return 0;
}
