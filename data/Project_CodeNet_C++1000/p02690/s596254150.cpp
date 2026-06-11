#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll x,i,j;
    cin >> x;
    int f = 0;
    for ( i = -118; i < 120; i++)
    {
        for ( j = -118; j < 120; j++)
        {
            if(i*i*i*i*i - j*j*j*j*j == x)
            {
                f = 1;
                break;
            }
        }
        if(f) break;    
    }
    cout << i << " " << j << endl;
}
