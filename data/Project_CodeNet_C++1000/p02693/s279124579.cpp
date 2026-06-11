#include <iostream>
using namespace std;

int main(void)
{
    int k, a, b; cin >> k >> a >> b;
    bool flag = 0;
    int tmp = k;
    while (tmp <= b)
    {
        if (tmp >= a && tmp <= b)
        {
            flag = true;
            break;
        }
        tmp += k;
    }
    if (flag) cout << "OK" << endl;
    else cout << "NG" << endl;
}