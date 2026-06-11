#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int Mn=a[0],x=1;
    for(int i=1;i<n;i++){
        if(Mn>=a[i])
            x++;
        Mn=min(Mn,a[i]);
    }
    cout<<x<<endl;
}
