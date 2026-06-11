#include <bits/stdc++.h>
using namespace std;

void Main()
{
    // x * 0.08 = A
    // x * 0.1 = B

    int a, b;
    cin >> a >> b;
    for (int i = 1; i < 20000; i++)
    {
        if(b == (int)(0.1*i) && a == (int)(0.08*i))
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
