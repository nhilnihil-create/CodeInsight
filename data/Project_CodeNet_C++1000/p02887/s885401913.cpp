#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,k,t,c=0;
    string a;
    cin>>n>>a;
    for(i=0; i<n; i++)
    {
        if(a[i]!=a[i+1])
        {//cout<<a[i]<<" ";
            c++;

        }

    }
    cout<<c<<endl;

}
