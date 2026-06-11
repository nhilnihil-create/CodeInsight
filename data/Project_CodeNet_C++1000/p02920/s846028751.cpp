#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int size = pow(2, N);
    vector<int>S(size);
    for (int i = 0; i < size; ++i) {
        cin >> S[i];
    }

    multiset<int, greater<int>> se;
    for (int x: S) {
        se.insert(x);
    }

    // 貪欲でいい
    vector<int>current;
    current.reserve(size);
    current.push_back(*(se.begin()));
    se.erase(se.begin());

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (1 << i); ++j) {
            auto iter = se.upper_bound(current[j]);
            if(iter != se.end()){
                current.push_back(*iter);
                se.erase(iter);
            } else{
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    cout << "Yes" << "\n";
    return 0;
}