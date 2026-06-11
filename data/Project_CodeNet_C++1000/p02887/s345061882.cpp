#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string s;
    cin >> N >> s;

    s.erase(unique(s.begin(), s.end()), s.end());
    cout << s.size() << endl;
}