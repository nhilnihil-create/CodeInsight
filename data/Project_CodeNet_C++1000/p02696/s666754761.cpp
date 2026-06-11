#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,n;
    cin>>a>>b>>n;
    cout<<(long long)((a*min(n,b-1ll))/b)-(long long)(min(n,b-1ll)/b)*a;
    return 0;
}
/***
32
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9 5

6
2 3 3 1 3 1
*/
