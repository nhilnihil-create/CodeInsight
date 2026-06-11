#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=2;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(a[0]!=1)
        cout<<"1";
    else if(a[1]!=2) cout<<"2";
    else cout<<"3";
}
