#include <math.h>
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MIN = 0;
const int MAX = 20000;

bool isRange(double v)
{
    if ((MIN <= v) && (v <= MAX))
    {
        return true;
    }
    return false;
}

int main()
{
    int a, b, ans;
    char op;

    while (cin >> a >> op >> b)
    {
        if (isRange(a) && isRange(b))
        {
            switch (op)
            {
            case '+':
                ans = a + b;
                 break;
            case '-':
                ans = a - b;
                break;
            case '*':
                ans = a * b;
                break;
            case '/':
                if (b != 0)
                {
                    ans = a / b;
                    break;
                }
                else
                {
                    continue;
                }
            case '?':
                return (0);
            }
            cout << ans << endl;
        }
    }
}