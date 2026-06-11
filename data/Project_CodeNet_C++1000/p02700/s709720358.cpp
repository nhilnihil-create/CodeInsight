#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


int main(){
    int a,b,c,d;
//    cout << 10/9 + 1;
    cin >> b >> a >> d >> c;
    int at,ct;
    if(d <= a){
        at = 1;
    }else{
        if(d % a == 0){
            at = d / a;
        }else{
            at = d / a + 1;
        }
    }
    if(b <= c){
        ct = 1;
    }else{
        if(b % c == 0){
            ct = b / c;
        }else{
            ct = b / c + 1;
        }
    }


    if(at <= ct)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}


