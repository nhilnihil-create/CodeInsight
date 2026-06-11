#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string sr = s;
    reverse(sr.begin(), sr.end());
    if (s == sr) {
        string s2 = s.substr(0, (s.length()-1)/2);
        string s2r = s2;
        reverse(s2r.begin(), s2r.end());
        if (s2 == s2r) {
            string s3 = s.substr((s.length()+3)/2-1);
            string s3r = s3;
            reverse(s3r.begin(), s3r.end());
            if (s3 == s3r) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}