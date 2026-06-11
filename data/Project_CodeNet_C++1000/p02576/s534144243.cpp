#include <bits/stdc++.h>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[ ";
    for(auto a : v)
        os << a << " ";
    os << "]";
    return os;
}

int main() {
    cout << fixed << setprecision(0);
    double N, X, T;
    cin >> N >> X >> T;
    cout << T * ceil(N / X) << endl;
    return 0;
}