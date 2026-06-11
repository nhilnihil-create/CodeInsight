#include <iostream>

using namespace std;

int main()
{
    int n, m, counter = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> m;
        if (m%2 == 1 && i%2 == 1)
            counter++;
    }
    cout << counter;
    return 0;
}
