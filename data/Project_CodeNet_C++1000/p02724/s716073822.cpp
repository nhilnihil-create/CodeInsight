#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, h = 0;
    cin >> a ;
    
    h += a / 500 * 1000;
    a %= 500;
    h += a / 5 * 5;

    cout << h << endl;

}
