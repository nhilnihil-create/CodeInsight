#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int cnt = 0;

    cin >> num;

    vector<int> vec(num);

    for (int i = 0; i < num; i++) cin >> vec.at(i);

    sort(vec.begin(), vec.end());

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            int k = lower_bound(vec.begin(), vec.end(), vec.at(i) + vec.at(j)) - vec.begin();

            cnt += max(k - (j + 1), 0);
        }
    }

    cout << cnt;
    //
}
