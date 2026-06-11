#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    long long n;
    cin >> n;
    while(n != 0){
        int digit = n % 10;
        if(digit == 7){
            cout << "Yes" << endl;
            return 0;
        }
        n = n / 10;
    }
    cout << "No" <<endl;
}
