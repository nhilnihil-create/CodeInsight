#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m=1,c=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==m)
        {
            c++;
            m++;
        }
    }
    if(c==0)
        cout<<"-1\n";
    else
        cout<<n-c<<"\n";
return 0;
}
