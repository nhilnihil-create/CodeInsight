#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, m = 0;
    cin >> n;
    vector<long long int>l(n);
    for (int i = 0; i < n; i++)cin >> l[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (l[i] != l[j] && l[j] != l[k] && l[k] != l[i]) {
                    if (l[i] + l[j] > l[k] && l[j] + l[k] > l[i] && l[k] + l[i] > l[j])m++;
                }
            }
        }
    }
    cout << m << endl;
    return 0;
}