#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#if 0
void print_array(vector<int> n) {
    for (int i = 0; i < n.size(); i++)
        cout << n.at(i) << " ";
    cout << endl;
}
#endif
int main() {
    string s; cin >> s;
    int n = s.size()+1;
    vector<int> a(n);

    char before = '-';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<' && before == '-') {
            before = s[i];
            a[i] = 0;
            a[i+1] = 1;
        }
        else if (s[i] == '<') {
            a[i+1] = a[i]+1;
        }
        else if (s[i] == '>') {
            before = '-';
        }
    }
    before = '-';
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '>' && before == '-') {
            before = s[i];
            a[i+1] = 0;
            a[i] = max(a[i], a[i+1]+1);
        }
        else if (s[i] == '>') {
            a[i] = max(a[i], a[i+1]+1);
        }
        else if (s[i] == '<') {
            before = '-';
        }
    }
    //print_array(a);
    Int sum = 0;
    for (auto e : a) {
        sum += (Int)e;
    }
    cout << sum << endl;
}
