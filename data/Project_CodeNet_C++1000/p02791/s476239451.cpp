#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],c=0,q,i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];

    }
    q=a[0];

    for(i=1;i<n;i++)
    {

        if(q>=a[i])
        {
            c++;
            q=a[i];
        }


    }
    cout<<c+1;








}
