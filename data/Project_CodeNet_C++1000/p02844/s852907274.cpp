#include <bits/stdc++.h>
using namespace std;

bool check(int i, string s) {
    string num = to_string(i);
    while (num.size() < 3) num = '0' + num;
    int idx = 0;
    for (int j=0; j<s.size(); j++) {
        if (idx == 3) return true;
        if (num[idx] == s[j]) {
            idx++;
        }
    }
    return idx == 3;
}

int main() {
    int N; cin >> N;
    string s; cin >> s;
    int counter = 0;
    for (int i=0; i<1000; i++) {
        if (check(i, s)) counter++;
    }
    cout << counter << endl;
}