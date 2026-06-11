#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char _ans[20];

void outputans(int n, int i, int index)
{
    if( i == n )
    {
        _ans[i] = '\0';
        cout << _ans << endl;
        return;
    }

    for( int j = 0; j <= index; j++)
    {
        _ans[i] = 'a' + j;       
        outputans(n, i + 1, max(index, j + 1) );
    }
}

int main()
{
    int n;
    cin >> n;
    outputans(n, 0, 0);
}