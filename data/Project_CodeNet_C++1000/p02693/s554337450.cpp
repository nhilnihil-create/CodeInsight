#include <bits/stdc++.h>
using namespace std;;

int main(){
    int k,a,b;
    cin >> k >> a >> b;
    if  (b-b%k >= a){
        cout << "OK" << endl;
    }else{
        cout << "NG" << endl;
    }
}