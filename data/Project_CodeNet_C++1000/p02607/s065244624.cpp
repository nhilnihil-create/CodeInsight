#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (i % 2 != 0)
            if (num % 2 != 0)
                result++;
    }
    cout << result;
    return 0;
}