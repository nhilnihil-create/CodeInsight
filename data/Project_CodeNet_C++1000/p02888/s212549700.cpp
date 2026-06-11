#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        v.push_back(l);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i=n-1; i>=2; i--) {
        for (int j=i-1; j>=1; j--) {
            for (int k=j-1; k>=0; k--) {
                if (v[j] + v[k] > v[i]) {
                    cnt++;
                } else {
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}