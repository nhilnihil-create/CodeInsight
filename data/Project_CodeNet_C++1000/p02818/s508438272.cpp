#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
    long long a,b,k;
    cin >> a >> b >> k;

    if(a >= k){
        cout << a -k << " "<< b;
    }else if(k <= a+b){
        cout << 0 << " " << b - (k - a);
    }else{
        cout << 0 << " " << 0;
    }
}
   
