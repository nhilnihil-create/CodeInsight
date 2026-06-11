#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> uniqued;
    for (unsigned int i = 0; i < a.size(); i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    unique_copy(a.begin(), a.end(), back_inserter(uniqued));
    cout << (a.size() == uniqued.size() ? "YES" : "NO") << endl;
}