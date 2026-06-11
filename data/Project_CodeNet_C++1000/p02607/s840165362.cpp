#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i % 2 == 0 && arr[i] % 2 == 1)
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}