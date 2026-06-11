#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    vector <int> vec (n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (vec[i] % 2 != 0 && (i + 1) % 2 != 0)
            cnt ++;
    }
    cout << cnt;
    return 0;
}
