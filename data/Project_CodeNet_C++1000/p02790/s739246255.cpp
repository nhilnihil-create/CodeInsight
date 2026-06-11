#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string aa, bb;
    for (int i = 0; i < b; i++) {
        aa += to_string(a);
    }
    for (int i = 0; i < a; i++) {
        bb += to_string(b);
    }
    vector<string> vec;
    vec.push_back(aa);
    vec.push_back(bb);
    sort(vec.begin(), vec.end());
    cout << vec.at(0) << endl;
}
