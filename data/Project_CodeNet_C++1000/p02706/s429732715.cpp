#include <bits/stdc++.h>
using namespace std;
#define ll long long
//const int mxN=2e5;
//int a[mxN];

int main()
{int n,m,sum=0;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum>n)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<n-sum;
    }
}
