#include <iostream>

using namespace std;

int main()
{
    int a , b , ans;
    cin >> a >> b;
    ans = a - (2 * b);
    if (ans <= 0){
        ans = 0;
    }
    cout << ans;
    return 0;
}
