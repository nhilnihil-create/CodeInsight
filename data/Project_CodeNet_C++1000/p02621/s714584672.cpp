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
    int a;
    cin >> a;
    cout << a + a * a + a * a * a << endl;
}
