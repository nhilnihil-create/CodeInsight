#include <bits/stdc++.h>

using namespace std;
//FILE *fi=freopen("1.txt","r",stdin);
long long n,a,b;
int main()
{
    cin>>a>>b>>n;
    n = min(n,b-1);
    cout<<(a*n)/b - a*(n/b);
    return 0;
}
