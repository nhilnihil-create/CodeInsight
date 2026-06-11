#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
queue<string> q;

string bfs() {
    ll cnt = 0;
    string s = "";

    for (int i = 1; i <= 9; ++i) {
        q.push(to_string(i));
    }

    while (!q.empty()) {
        s = q.front();
        q.pop();
        cnt++;
        if (cnt == k) break;

        int num = atoi(&s[(int)s.length()-1]);
        if (num == 0) {
            q.push(s + to_string(num));
            q.push(s + to_string(num + 1));
        } else if (num == 9) {
            q.push(s + to_string(num - 1));
            q.push(s + to_string(num));
        } else {
            q.push(s + to_string(num - 1));
            q.push(s + to_string(num));
            q.push(s + to_string(num + 1));
        }
    }
    return s;
}

int main () {
    cin >> k;
    cout << bfs() << endl;
}
