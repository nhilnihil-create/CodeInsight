#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long X;
    cin >> X;

    long long money = 100;
    long long year = 0;

    while(money < X){
        money = money + (money/100);
        year ++;
    }

    cout << year << endl;

    return 0;
}
