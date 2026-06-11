#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,a,i,c=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a>=k)
            c++;
    }
    cout<<c<<endl;
}
