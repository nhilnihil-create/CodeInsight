#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, long long int> a;
    vector<char> tmp(10);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 10; j++) {
            tmp[j] = str[j];
        }
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < 10; j++) {
            str[j] = tmp[j];
        }
        a[str]++;
    }

    long long int output = 0;

    for (auto num : a) {
        output += num.second * (num.second - 1) / 2;
    }

    cout << output << endl;

    return 0;
}
