#include <iostream>
using namespace std;

int main(void)
{
    int a[9] = {};
    bool check[9] = {};
    int n = 0;
    for (int i = 0; i < 9; ++i)
    {
        cin >> a[i];
    }
    cin >> n;

    int b[n] = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    /*
    cout << "inputed\n";
    for (int i = 0; i < 9; ++i)
    {
        cout << "a[" << i << "] == " << a[i] << endl;
    }
    cout << "n == " << n << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "b[" << i << "] == " << b[i] << endl;
    }
    */

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i] == b[j])
            {
                check[i] = true;
            }
        }
    }

    /*
    cout << "checked\n";
    for (int i = 0; i < 9; ++i)
    {
        if (check[i] == true)
        {
            cout << "check[" << i << "] == "
                 << "true" << endl;
        }
        else
        {
            cout << "check[" << i << "] == "
                 << "false" << endl;
        }
    }
    */

    if (check[0] == true && check[1] == true && check[2] == true)
    {
        cout << "Yes";
    }
    else if (check[3] == true && check[4] == true && check[5] == true)
    {
        cout << "Yes";
    }
    else if (check[6] == true && check[7] == true && check[8] == true)
    {
        cout << "Yes";
    }

    else if (check[0] == true && check[3] == true && check[6] == true)
    {
        cout << "Yes";
    }
    else if (check[1] == true && check[4] == true && check[7] == true)
    {
        cout << "Yes";
    }
    else if (check[2] == true && check[5] == true && check[8] == true)
    {
        cout << "Yes";
    }

    else if (check[0] == true && check[4] == true && check[8] == true)
    {
        cout << "Yes";
    }
    else if (check[2] == true && check[4] == true && check[6] == true)
    {
        cout << "Yes";
    }

    else
    {
        cout << "No";
    }

    return 0;
}