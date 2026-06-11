#include <iostream>
using namespace std;

int main(void)
{
    int n; cin >> n;
    int hon[5] = {2,4,5,7,9};
    int pon[4] = {0,1,6,8};
    int bon[1] = {3};
    n = n % 10;

    for (int a:hon)
    {
        if (a == n)
        {
            cout << "hon" << endl;
            return 0;
        }
    }
    for (int a:pon)
    {
        if (a == n)
        {
            cout << "pon" << endl;
            return 0;
        }
    }
    for (int a:bon)
    {
        if (a == n)
        {
            cout << "bon" << endl;
            return 0;
        }
    }
}