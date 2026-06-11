#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,n,a,i,s=0;
    cin>>h>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        s+=a;
    }
    cout<<(s>=h?"Yes":"No")<<endl;
}
