#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    int a[n];//c[100001]={};
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            //++c[a[i]];
        }
    sort(a,a+n);
    cout<<abs(a[n/2]-a[(n/2)-1]);
    return 0;
}

