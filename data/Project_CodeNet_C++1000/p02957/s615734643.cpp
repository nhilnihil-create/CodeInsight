#include<iostream>
using namespace std;
int main()
{
    int a,b,k;
    cin >> a >> b;
    if(a>=0 && b<=1000000000)
    {
        if(((a+b)%2)==0)
        {
            k= (a+b)/2;
            cout << k << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
