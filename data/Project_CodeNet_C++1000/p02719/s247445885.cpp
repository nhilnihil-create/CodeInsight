#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    
    long long amari = n % k;
    
    long long next = abs(amari - k);
    cout << min(amari,next) << endl;
}