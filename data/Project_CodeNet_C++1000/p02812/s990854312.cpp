#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0;
    string a;
    cin>>n;
    cin>>a;
    for(i=0;i<n;i++)
    {
        if((a[i]=='A')&&(a[i+1]=='B')&&(a[i+2]=='C'))
        {
            c++;
        }

    }
    cout<<c<<endl;
    return 0;
}