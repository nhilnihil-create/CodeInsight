#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

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
    int n;
    cin >> n;
    int *w = inputint(n);
    int ans = 100 * 100 * 100;
    for( int t = 1; t < n; t++ )
    {
        int s1 = 0;
        int s2 = 0;
        for(int i = 0; i < t; i++ ) s1 += w[i];
        for(int i = t; i < n; i++ ) s2 += w[i];
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans;
}