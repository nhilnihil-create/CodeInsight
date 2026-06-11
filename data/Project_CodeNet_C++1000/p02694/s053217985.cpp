#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,b=100,c=0;
    cin >> x;
    while(b<x){
        b += b/100;
        ++c;
    }
    cout << c;
    return 0;
}