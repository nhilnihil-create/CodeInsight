#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A+1), b(B+1);
    int a_min = 100001, b_min = 100001;
    for (int i = 1; i <= A; i++) {
        cin >> a.at(i);
        a_min = min(a_min, a.at(i));
    }
    for (int i = 1; i <= B; i++) {
        cin >> b.at(i);
        b_min = min(b_min, b.at(i));
    }
    int ret = a_min + b_min;
    int tmp_a, tmp_b, tmp;
    for (int i = 1; i <= M; i++) {
        cin >> tmp_a >> tmp_b >> tmp;
        tmp = a.at(tmp_a) + b.at(tmp_b) - tmp;
        ret = min(ret, tmp);
    }
    cout << ret << endl;
}