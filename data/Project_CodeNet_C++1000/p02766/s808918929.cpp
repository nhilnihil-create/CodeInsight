#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;

int main()
{
    int n,r;
    cin>>n>>r;
    int dig = (int)(floor( log(n) /
                         log(r)) + 1);
    cout<<dig;
}
