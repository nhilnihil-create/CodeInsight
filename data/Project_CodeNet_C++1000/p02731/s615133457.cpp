#include <bits/stdc++.h>
using namespace std;

int main() {
    int l;
    cin >> l;
    string v = to_string(l*l*l / 27) + to_string((long double)((l*l*l)%27)/27L).substr(1);
    cout << v << endl;
    return 0;
}