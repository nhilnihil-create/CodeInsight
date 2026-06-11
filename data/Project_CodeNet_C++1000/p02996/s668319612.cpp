#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    long long tmp1, tmp2;
    long long kosu = 0;

    cin >> num;

    // 締め切り, 工数
    vector<pair<long long, long long>> p(num);

    for (int i = 0; i < num; i++) {
        cin >> tmp1 >> tmp2;
        p.at(i) = make_pair(tmp2, tmp1);
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < num; i++) {
        long long a, b;
        tie(b, a) = p.at(i); // 工数、締め切り(上で反転した分を元に戻す) 

        kosu += a;

        if (kosu > b) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}