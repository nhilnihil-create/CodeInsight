#include <bits/stdc++.h>
using namespace std;




























int main () {
    long long N;
    cin >> N;
    vector<long long> vect;
    while (N > 0) {
        if (N % 26 == 0) {
            vect.push_back(26);
            N -= 26;
        }
        else {
            vect.push_back(N % 26);
        }
        N /= 26;
    }
    reverse (vect.begin(), vect.end());

    string s;
    for (long long i: vect) {
        s.push_back((char)('a' + i - 1));
    } 

    cout << s << endl;
}