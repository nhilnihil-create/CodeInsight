#include <bits/stdc++.h>
using namespace std;

int	main()
{
    string n;
    int sum = 0, i = 0;
    cin >> n;

    while(n[i])
    {
        sum += n[i] - '0';
        i++;
    }
    if (sum % 9 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}