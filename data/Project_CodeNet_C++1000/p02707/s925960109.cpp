#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    int tmp;
    for (int i = 0; i < n-1; i++) {
        cin >> tmp;
        a.at(tmp-1)++;
    }

    for (int i = 0; i < n; i++) {
        cout << a.at(i) << endl;
    }
    
    return 0;
}
