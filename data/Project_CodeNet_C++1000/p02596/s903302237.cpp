#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k;
    cin >> k;
    int num = 7 % k;
    int cnt = 1;
    map<int, int> ja_foi;
    while(num != 0 && !ja_foi[num]) {
        ja_foi[num] = 1;
        num = (num * 10 + 7) % k;
        cnt++;
    }
    if(!num) {
        cout << cnt << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}
