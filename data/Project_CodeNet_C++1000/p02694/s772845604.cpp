#include<iostream>
using namespace std;

int main () {
    long long int X; cin >> X;
    int year = 0;
    long long int money = 100;
    while (1) {
        if (money >= X) {
            cout << year << endl;
            break;
        }
        money += money / 100;
        year++;
    }
}
