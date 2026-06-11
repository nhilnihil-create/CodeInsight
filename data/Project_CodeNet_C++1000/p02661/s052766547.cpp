#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int *g_a;
int *g_b;
int main(void)
{
    int n;
    cin >> n;
    std::vector<int> a;
    std::vector<int> b;

    for( int i = 0; i < n; i++ )
    {
        int ta, tb;
        cin >> ta >> tb;
        a.push_back(ta);
        b.push_back(tb);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ans;

    if( n % 2 == 1 )
    {
        ans = b.at( n / 2 ) - a.at( n / 2 ) + 1;
    }
    else
    {
        ans = b.at( n / 2 - 1 ) + b.at( n / 2 ) - a.at( n / 2 - 1 ) - a.at( n / 2 ) + 1;
    }
    cout << ans;    
}