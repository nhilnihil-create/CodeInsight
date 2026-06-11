#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i=0; i<n; i++) {
        if (a[i] == v[0]) {
            cout << v[1] << endl;
        } else {
            cout << v[0] << endl;
        }
    }
}