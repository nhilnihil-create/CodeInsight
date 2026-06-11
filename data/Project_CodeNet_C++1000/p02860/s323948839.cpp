#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        string s;
        cin >> s;

        vector<string> vec(n);

        for (int i = 0; i < s.length(); ++i) {
            vec[i] = s[i];
        }

        string temp1, temp2;
        for (int i = 0; i < vec.size() / 2; ++i) {
            temp1 += vec[i];
        }
        reverse(vec.begin(), vec.end());
        for (int i = 0; i < vec.size() / 2; ++i) {
            temp2 += vec[i];
        }

        reverse(temp2.begin(), temp2.end());

        if (temp1 == temp2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}
