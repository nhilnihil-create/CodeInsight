#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    if(k%2 == 0 || k%5 == 0) {
        cout << -1 << '\n';
        return 0;
    } else {
        int index = 1, repsept = 7;
        while(1) {
            if(repsept%k == 0) {
                cout << index << '\n';
                return 0;
            }
            repsept = repsept*10 + 7;
            repsept %= k;
            index++;
        }
    }
}
