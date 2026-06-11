#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,n;
    cin>>h>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        h=h-a[i];
    }
    if(h>0)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
