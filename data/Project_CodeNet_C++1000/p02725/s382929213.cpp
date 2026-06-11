#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> k >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int max_val = a[0];
    for (int i=0; i<n-1; i++) {
        if (max_val < abs(a[i] - a[i+1])) max_val = abs(a[i] - a[i+1]);
    }
    max_val = max(max_val, k-a[n-1]+a[0]);
    cout << k - max_val << endl; 
   
    return 0;
}