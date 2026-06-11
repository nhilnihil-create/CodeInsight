#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    if( a<=b || a <= 2*b){
        cout << 0;
    }
    else cout << a - b - b;
}