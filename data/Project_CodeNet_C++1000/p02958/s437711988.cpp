#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[100];

    for(int i=0;i<n;i++)
    {
       cin>>p[i];
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]!=i+1)
        {
            c++;
        }
    }

    if(c<=2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
