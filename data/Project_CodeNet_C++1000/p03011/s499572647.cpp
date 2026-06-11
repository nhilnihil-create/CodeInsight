#include<iostream>
using namespace std;
int main (void){

    int p, q, r, a, b, c, min;

    cin >> p >> q >> r;

    a = p + q;
    min = a;
    b = q + r;
    if(b < min)
    min = b;


    c = r + p;
    if(c< min)
    min = c;
    cout << min << endl;

    return 0;
}