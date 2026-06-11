#include <bits/stdc++.h>


#define long long long int

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int, int> pi;


int main() {

    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second >> v[i].first;
    }
    string s;
    cin >> s;
    long res = 0;
    int index = 0;
    while (index < n && v[index++].second != s);
    while (index < n) {
        res += v[index++].first;
    }

    cout << res;

    return 0;
}