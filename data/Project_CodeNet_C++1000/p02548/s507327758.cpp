#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
long long n,m;

int main()
{
    IO;
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<n;i++)
    {
        res+=(n-1)/i;
    }

    cout<<res<<endl;
    return 0;
}
