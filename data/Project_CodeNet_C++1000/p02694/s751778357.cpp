#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


int main(){
    long long x;
    cin >> x;
    long long base = 100;
    int count = 0;
    while (base < x){
        count++;
        base += base /100;
    }
    cout << count << endl;
}


