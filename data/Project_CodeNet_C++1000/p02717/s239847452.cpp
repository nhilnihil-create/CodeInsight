#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> v;
    for(int i = 0; i < 3;  i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
    iter_swap(v.begin() + 1, v.begin() + 2);
    iter_swap(v.begin() + 0, v.begin() + 1);
    for(auto u : v)
        cout << u << " ";
    cout << "\n";
    return 0;
}
