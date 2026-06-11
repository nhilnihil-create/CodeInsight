#include <bits/stdc++.h>

using namespace std;

vector<int> next_int_vector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v.at(i);
    }
    return v;
}

int main() {
    string s, t;
    cin >> s >> t;

    int distance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) != t.at(i)) distance++;
    }
    cout << distance << endl;
}
