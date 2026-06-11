#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long sum = 0;
    while(n){
        if(n % 3 != 0 && n % 5 != 0)
            sum +=n;
        n--;
    }
    cout << sum <<endl;
}
