#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,a[1000],t,s=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    sort(a,a+n,greater<int>());
    cout<<(a[m-1]*4*m<s?"No":"Yes")<<endl;
}
