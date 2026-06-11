#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, k; k = 1;
    string s, pre, post;
    cin >> s; pre = s.at(0); post = "";

    for (i = 1; i < s.size(); i++) {
        post += s.at(i);
        if (pre != post) {
            k++;
            pre = post;
            post = "";
        }
    }
    cout << k << endl;
    return 0;
}