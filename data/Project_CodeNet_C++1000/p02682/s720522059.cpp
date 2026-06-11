#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int ans = 0;
    if(k >= a + b){
        cout << a - (k - a - b) << endl;
    }else if(k < a){
        cout << k << endl;
    }else{
        cout << a << endl;
    }
}


