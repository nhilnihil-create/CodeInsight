#include <bits/stdc++.h>

using namespace std;

int arr[300000];

int main()
{
    int n, min, count = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    min = arr[0];
    for(int i = 0; i < n; i++)
    {
        if (min >= arr[i])
        {
            min = arr[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
