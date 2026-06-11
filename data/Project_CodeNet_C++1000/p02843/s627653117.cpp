#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int X,syou=0;
    cin >> X;

    if(X < 99)
        cout << 0 << endl;
    else if(X >= 2000)
        cout << 1 << endl;
    else{
        syou = X / 100;
        if(X <= (syou * 100 + syou * 5))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    
    

}