#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X;
    cin >> X;
    int year = 0;
    long long money = 100;

    while(money < X){
        money += money/100;
        year++;
    }

    cout << year << endl;
}