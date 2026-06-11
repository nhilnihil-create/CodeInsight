#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 3-(a+b)%3;
    cout << ans << endl;
    return 0;
}