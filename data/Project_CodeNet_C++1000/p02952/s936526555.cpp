#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int cnt = 0;

    cin >> num;

    for (int i = 1; i <= num; i++) {
        string str = to_string(i);
        if (str.size() % 2 == 1) cnt++;
    }

    cout << cnt;
    //
}
