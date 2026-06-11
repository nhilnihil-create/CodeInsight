#include <iostream>

using namespace std;

int main()
{
    int a , b , ans;
    cin >> a >> b;
    if (a >= 10){
        cout << b;
    }else{
        ans = b + (100 * (10 - a));
        cout << ans;
    }
    return 0;
}
