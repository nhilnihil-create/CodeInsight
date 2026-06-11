#include<iostream>
using namespace std;
int main()
{
    int a, b, c;

    cin >> a >> b;

    if(a>=1&&b>=1&&a<=20&&b<=20)
    {
        if(a<10&&b<10)
        {
            c=a*b;
            cout << c << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}
