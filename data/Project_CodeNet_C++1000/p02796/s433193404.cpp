#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;

    cin >> num;

    vector<pair<long long, long long>> p(num);
    for (int i = 0; i < num; i++) {
        long long a, b;
        cin >> a >> b;
        p.at(i) = make_pair(a+b, a-b);
    }

    sort(p.begin(), p.end());

    long long right = 0;
    long long cnt = 0;
    for (int i = 0; i < num; i++) {
        long long tmpL = p.at(i).second;
        long long tmpR = p.at(i).first;
        if (i == 0) {
            right = tmpR;
            continue;
        }
        if (tmpL < right) {
            cnt++;
        } else {
            right = tmpR;
        }
    }

    cout << num - cnt << endl;
    //
}
