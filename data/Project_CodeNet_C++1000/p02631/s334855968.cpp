#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int i=0;i<n;i++) {
        cin >> a.at(i);
        x = (x^a.at(i));
    }
    for (int i=0;i<n;i++) {
        cout << (x^a.at(i));
        if (i==n-1) cout << endl;
        else cout << " ";
    }
}