#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    string str;

    cin >> str;

    num = str.size();
    vector<int> vec(num, 0);

    for (int x = 0; x < 2; x++) {
        int cnt = 0;
        for (int i = 0; i < num; i++) {
            if (str.at(i) == 'R')
                cnt++;
            else {
                vec.at(i) += cnt / 2;
                vec.at(i - 1) += (cnt + 1) / 2;
                cnt = 0;
            }
        }

        reverse(vec.begin(), vec.end());
        reverse(str.begin(), str.end());
        for (int i = 0; i < num; i++) {
            if (str.at(i) == 'L')
                str.at(i) = 'R';
            else
                str.at(i) = 'L';
        }
    }

    for (int i = 0; i < num; i++) { cout << vec.at(i) << " "; }
}
