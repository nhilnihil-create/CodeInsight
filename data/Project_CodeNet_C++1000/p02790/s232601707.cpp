#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    if(a > b){
        while(a > 0){
            cout << b;
            a--;
        }
    }
    else{
        while(b > 0){
            cout << a;
            b--;
        }
    }

    cout << endl;
}