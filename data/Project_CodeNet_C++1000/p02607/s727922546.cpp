#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, res = 0;
    cin>>n;
    int a[n+2];
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(i % 2 && a[i] % 2)res++;
    }
    cout<<res<<endl;
}
