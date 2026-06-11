#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num, x;
    int sum = 0;

    cin >> num >> x;

    int index = 1;
    while (sum <= x && index <= num) {
        int tmp;
        cin >> tmp;
        sum += tmp;

        if (sum > x) break;
        index++;
    }

    cout << index;
    //
}
