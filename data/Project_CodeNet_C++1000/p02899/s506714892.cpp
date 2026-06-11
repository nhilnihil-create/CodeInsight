#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    vector<int>::iterator itr;
    for (int j = 1; j <= n; j++) {
        itr = find(a.begin(), a.end(), j);
        cout << distance(a.begin(), itr) + 1 << " ";
    }
    cout << endl;
}
