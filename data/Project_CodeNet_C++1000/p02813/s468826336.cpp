#include <bits/stdc++.h>
using namespace std;

int read_int(int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        s = 10 * s + m;
    }

    return s;
}

int p, q;
int cnt_p, cnt_q;

int cnt = 0;
void func(int s, vector<int> a) {
    if (a.size() == 0) {
        cnt++;
        if (s == p)
            cnt_p = cnt;
        if (s == q)
            cnt_q = cnt;

        return;
    }

    for (int i = 0, n = a.size(); i < n; i++) {
        vector<int> _a = a;
        _a.erase(vector<int>::const_iterator(_a.begin() + i));
        func(10 * s + a.at(i), _a);
    }
}

int main() {
    int n;
    cin >> n;

    p = read_int(n);
    q = read_int(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a.at(i) = i + 1;

    func(0, a);

    cout << abs(cnt_p - cnt_q) << endl;
}