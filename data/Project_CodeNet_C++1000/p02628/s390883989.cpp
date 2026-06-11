#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;  cin >> n;
    int k;  cin >> k;

    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int sum = 0;
    for (int i = 0; i < k; i++){
        sum += arr[i];
    }

    cout << sum << endl;

    return 0;
}
