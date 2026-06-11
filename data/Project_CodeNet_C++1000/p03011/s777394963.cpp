#include <bits/stdc++.h>

using namespace std;

int main() {
    int P, Q, R;
    cin >> P >> Q >> R;
    vector<int> vec;

    vec.push_back(P + Q);
    vec.push_back(P + R);
    vec.push_back(Q + R);

    sort(vec.begin(), vec.end());

    cout << vec[0] << endl;

}