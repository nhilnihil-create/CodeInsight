#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int l = 0;
    int r = 0;
    int Min = 99999;

    cin >> num;

    vector<int> vec(num);
    for (int i = 0; i < num; i++) {
        cin >> vec.at(i);
        r += vec.at(i);
    }

    Min = r;
    for (int i = 0; i < num; i++) {
        l += vec.at(i);
        r -= vec.at(i);

        Min = min(Min, abs(l - r));
    }

    cout << Min;
    //
}
