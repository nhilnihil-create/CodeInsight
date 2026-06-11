#include <bits/stdc++.h>
using namespace std;

int main() {
    
    unsigned long long int X,S = 100;
    cin >> X;

    unsigned int count = 0;
    while(1){
        S += (S / 100);
        count++;
        if(S >= X) break;
    }
    cout << count <<endl;
}