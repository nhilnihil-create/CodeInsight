#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct query {
    int type , side;
    char c;
} info[N];

string s;

void go (int i , bool rev) {
    if (i == -1) {
        if (rev)
            reverse(s.begin() , s.end());
        cout << s;
        return;
    }

    if (info[i].type == 1) {
        rev ^= 1;
        go(i - 1 , rev);
    } else {
        info[i].side ^= rev;
        if (info[i].side) {
            go(i - 1 , rev);
            cout << info[i].c;
        } else {
            cout << info[i].c;
            go(i - 1 , rev);
        }
    }
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#ifdef LOCAL
    freopen("input.in" , "r" , stdin);
#endif
    int q;
    cin >> s >> q;

    for (int i = 0 ;i < q ;i++) {
        cin >> info[i].type;
        if (info[i].type == 2) {
            cin >> info[i].side >> info[i].c;
            info[i].side--;
        }
    }

    go(q - 1 , 0);
}
