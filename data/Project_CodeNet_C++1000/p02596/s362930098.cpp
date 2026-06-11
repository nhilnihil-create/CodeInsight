#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    if (k % 7 == 0) k /= 7;
    if (k % 2 == 0 || k % 5 == 0) {
        cout << -1 << endl;
        return 0;
    }
    int n = 1, cnt = 1;
    while (n % k != 0) {
        n = (n*10 + 1) % k;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}