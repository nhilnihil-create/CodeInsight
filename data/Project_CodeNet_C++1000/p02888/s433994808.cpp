#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> l;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        l.push_back(x);
    }
    sort(l.begin(), l.end());
    ll count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int first_index = j + 1;
            int last_index = n - 1;
            while (last_index - first_index > 1) {
                int medium_index = (first_index + last_index) / 2;
                if (l[medium_index] < l[i] + l[j]) {
                    first_index = medium_index;
                }
                else {
                    last_index = medium_index;
                }
            }
            if (l[first_index] >= l[i] + l[j]) {
                ;
            }
            else if (l[last_index] >= l[i] + l[j]) {
                count += first_index - j;
            }
            else {
                count += last_index - j;
            }
        }
    }
    cout << count << endl;
    return 0;
}