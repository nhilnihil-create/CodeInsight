#include <iostream>
using namespace std;
#define ll long long
const ll MAX = 1e9;

int main() {
    ll s;
    cin >> s;
    if (s <= MAX) {
        printf("0 0 0 1 %d 0", s);
    } else if (s == 1e18) {
        printf("0 0 %d 0 0 %d", MAX, MAX);
    } else {
        int a = s / MAX + 1;
        int b = MAX - s % MAX;
        printf("0 0 %d 1 %d %d", a, b, MAX);
    }
}