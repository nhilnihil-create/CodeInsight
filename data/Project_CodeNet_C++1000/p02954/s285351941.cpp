#include <bits/stdc++.h>
using namespace std;
int main() {
    string S; cin >> S;
    vector<long long>A;
    for (long long i = 1; i < S.size(); i++) {
        if (S.at(i) != S.at(i - 1)) {
            A.push_back(i);
        }
    }
    bool check = true; //true...right,false...left
    vector<pair<long long, long long>>ans(S.size());
    for (long long i = 0; i < S.size(); i++) {
            auto it = upper_bound(A.begin(), A.end(), i);
            if (S.at(i) == 'R') check = true;
            else check = false;
        if (check) {
            ans.at(i).first = *it;
            ans.at(i).second = (ans.at(i).first - i) % 2;
        }
        else {
            long long pos = it - A.begin();
            ans.at(i).first = A.at(pos - 1);
            ans.at(i).second = (i - ans.at(i).first) % 2;
        }
    }
    vector<long long>B(S.size(), 0);
    for (long long i = 0; i < S.size(); i++) {
        B.at(ans.at(i).first - ans.at(i).second)++;
    }
    for (long long i = 0; i < S.size(); i++) {
        cout << B.at(i);
        if (i != S.size() - 1) cout <<  ' ';
    }
    cout << endl;
}