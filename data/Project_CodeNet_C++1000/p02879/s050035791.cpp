#include <iostream>

using namespace std;

int main()
{
    int x, y;
    
    cin >> x;
    cin >> y;
    
    if ( x > 0  &&  x < 10  &&  y > 0  &&  y < 10 ){
        cout << (x*y);
    }
    else{
        cout << ("-1");
    }

    return 0;
}
