#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d;

    if(c % b == 0)e = c / b;
    else e = c / b + 1; 
    if(a % d == 0)f = a / d;
    else f = a / d + 1; 

    if(e > f)cout << "No" << endl;
    if(e <= f)cout << "Yes" << endl;
}