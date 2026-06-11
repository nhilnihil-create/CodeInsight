#include<iostream>
using namespace std;

int main()
{
    int temp,a, b, c,temp1,temp2,temp3;
    cin >> a >> b >> c;

    temp1 = a;
    a = b;
    b = temp1;
    temp2 = a;
    a = c;
    c = temp2;
    cout << a << " " << b << " " << c << endl;
    //cout << b << endl;
    //cout << c << endl;
    return 0;
}