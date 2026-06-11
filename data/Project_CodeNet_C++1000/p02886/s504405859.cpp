/// TAKOYAKI FESTIVAL 2019......At coder contest 143
#include<iostream>
using namespace std;

#define ar array
#define endl '\n'
#define max 10000
int main()
{
    int mal=0;
    int ar[max];
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            mal=mal+(ar[i]*ar[j]);
        }
    }
    cout<<mal<<endl;
}
