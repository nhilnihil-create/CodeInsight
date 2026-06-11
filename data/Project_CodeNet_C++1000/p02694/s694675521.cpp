#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll X;
    ll money = 100;
    cin >> X;
    int year = 0;
    while(true) {
        money = money + money / 100;
        year++;
        if (money >= X) {
            cout << year << endl;
            exit(0);
        }
    }
}