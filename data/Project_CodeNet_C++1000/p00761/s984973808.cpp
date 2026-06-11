#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
int next(int n, int l) {
    string s = to_string(n);
    while(s.size() < l) s = "0" + s;
    sort(s.begin(), s.end());
    int low = stoi(s);
    reverse(s.begin(), s.end());
    int high = stoi(s);
    return high - low;
}
int main() {
    int A, L;
    while(cin >> A >> L && L > 0) {
        map<int, int> m;
        int x = A;
        for(int i = 0;;i++) {
            if(m.count(x)) {
                cout << m[x] << " " << x << " " << i - m[x] << endl;
                break;
            }
            m[x] = i;
            x = next(x, L);
        }
    }
    return 0;
}