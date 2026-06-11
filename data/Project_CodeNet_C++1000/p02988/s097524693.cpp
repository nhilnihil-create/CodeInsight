#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int cnt = 0;

    cin >> num;
    vector<int> vec(num);

    for (int i = 0; i < num; i++) cin >> vec.at(i);

    for (int i = 0; i < num - 2; i++) {
        if (vec.at(i) <= vec.at(i + 1) && vec.at(i + 1) <= vec.at(i + 2)) {
            cnt++;
        } else if (vec.at(i) >= vec.at(i + 1) && vec.at(i + 1) >= vec.at(i + 2)) {
            cnt++;
        }
    }

    cout << cnt;
    //
}
