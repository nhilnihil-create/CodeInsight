#include <iostream>
using namespace std;

int main(void)
{
    int N, i;
    long long a[100001], b, zero;
    zero = 0;
    b = 1;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            zero++;
    }
    if (zero > 0)
    {
        cout << "0\n";
        return 0;
    }
    for (i = 0; i < N; i++)
    {

        if (a[i] <= 1000000000000000000 / b)
        {
            b = b * a[i];
        }
        else
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << b << endl;
    return 0;
}
