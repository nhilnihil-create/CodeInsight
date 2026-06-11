#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, m;
    cin >> a >> b >> m;

    vector<int> a_v(a);
    vector<int> b_v(b);
    int a_min = 100001, b_min = 100001;
    for (int i = 0; i < a; i++) {
        cin >> a_v.at(i);
        if (a_min > a_v.at(i)) a_min = a_v.at(i);
    }
    for (int i = 0; i < b; i++) {
        cin >> b_v.at(i);
        if (b_min > b_v.at(i)) b_min = b_v.at(i);
    }

    int sum_min = a_min + b_min;
    int a_i, b_i, tmp, c;
    for (int i = 0; i < m; i++) {
        cin >> a_i >> b_i >> c;
        tmp = a_v.at(a_i-1) + b_v.at(b_i-1) - c;
        if (tmp < sum_min) sum_min = tmp;
    }

    cout << sum_min << endl;
    
    return 0;
}
