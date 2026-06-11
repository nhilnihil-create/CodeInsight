#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,t;
    cin>>n>>x>>t;
    int m;
    if (n%x) m = n/x + 1;
    else m = n/x;
    cout << m * t << '\n';
    return 0;
}