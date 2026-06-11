#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    if(2*b < a){
        cout << a - 2 * b << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}