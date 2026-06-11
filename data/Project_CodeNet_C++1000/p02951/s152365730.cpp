#include<iostream>
using namespace std;
int main (void){

    int a, b, c;

    cin >> a >> b >> c;

    b = b + c;

    a = b - a;

    if(a < 0)
    a = 0;

    cout << a <<endl;



    return 0;
}