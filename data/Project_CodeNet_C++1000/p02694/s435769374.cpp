#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long int X,money=100,year=0;
    cin >> X;
    while(X>money){
        year++;
        money+=money/100;
    }
    cout << year;
}