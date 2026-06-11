#include <iostream>
using namespace  std;
int main()
{
    int a,b,c,d,e;
    cin >> a >> b >> c;
    d = a - b;
    e = b - c;
    if(d < 0 && e < 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
