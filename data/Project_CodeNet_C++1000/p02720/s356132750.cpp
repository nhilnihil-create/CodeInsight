#include <bits/stdc++.h>
using namespace std;

int main() {

    int k;
    cin >> k;
    queue<long long> coada;
    for(int i = 1; i <= 9; i++) {
        coada.push(i);
    }
    while(1) {
        long long x = coada.front();
        k--;
        coada.pop();
        if(k == 0) {
            cout << x;
            break;
        }
        for(int i = max(x % 10 - 1, 0LL); i <= min(x % 10 + 1, 9LL); i++) {
            coada.push(x * 10 + i);
        }
    }
    return 0;
}
