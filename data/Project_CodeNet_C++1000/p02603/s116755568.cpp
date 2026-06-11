#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int sNum, mNum;
    int Min = 0;
    int Max = 0;

    cin >> num;
    long long kin = 1000;
    vector<int> vec(num);
    for (int i = 0; i < num; i++) cin >> vec.at(i);

    for (int i = 0; i < num - 1; i++) {
        if (vec.at(i) < vec.at(i + 1)) {
            long long has;
            has = kin % vec.at(i);
            kin = kin / vec.at(i);
            kin = kin * vec.at(i + 1) + has;

        }
    }

    cout << kin;
    //
}
