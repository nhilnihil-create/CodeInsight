#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    string a;
    string temp1;
    string temp2;
    int len_a;
    int c,x;
    int i;
    
    for (;;){
        cin >> a;
        if ( a== "-") break;
        len_a = a.length();
        cin >> c;
        for ( i = 0 ; i < c ; i++){
            cin >> x;
            temp1 = a.substr(0,x);
            temp2 = a.substr(x,len_a-x);
            a = temp2 + temp1;
            //cout << a << endl;
        }
        cout << a << endl;
    }
    
    return 0;
}