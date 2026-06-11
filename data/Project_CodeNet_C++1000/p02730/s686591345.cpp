#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int n = s.size();

    string s_ = s;
    reverse(s_.begin(), s_.end());
    string a = s.substr(0, (n-1)/2);
    string a_ = s.substr(0, (n-1)/2);
    reverse(a_.begin(), a_.end());
    string b = s.substr((n+3)/2-1);
    string b_ = s.substr((n+3)/2-1);
    reverse(b_.begin(), b_.end());

    string output = "No";
    if (s == s_ && a == a_ && b == b_) {
        output = "Yes";
    }
    cout << output << endl;
    return 0;
}
