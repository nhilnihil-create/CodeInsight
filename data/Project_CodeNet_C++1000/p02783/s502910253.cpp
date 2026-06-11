#include <iostream>

using namespace std;

int main()
{
    int a , b , ans;
    cin >> a >> b;
    ans = a / b;
    if (a % b != 0){
        ans++;
    }
    cout << ans;
    return 0;
}
