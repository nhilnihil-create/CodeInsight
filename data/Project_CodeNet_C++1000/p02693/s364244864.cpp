#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    int a, b;
    cin >> k;
    cin >> a >> b;

    int b_div, a_div;
    b_div = b / k;
    a_div = (a - 1) / k;
    
    if (b_div - a_div) cout << "OK" << endl;
    else cout << "NG" << endl;
}