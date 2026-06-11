#include<iostream>
using namespace std;
int main()
{
    int n,a[100];
    int c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2==1)
        {
            if(a[i]%2==1)
                c++;
        }
    }
    cout<<c;
}

