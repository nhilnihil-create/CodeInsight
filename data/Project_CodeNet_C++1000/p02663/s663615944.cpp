#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;

int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int* inputint(int n)
{
    int *ans = mallocint(n);
    for( int i = 0; i < n; i++ ) cin >> ans[i];
    return ans;
}

int main()
{
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    cout << h2 * 60 + m2 - (h1 * 60 + m1) - k;
    return 0;    
}