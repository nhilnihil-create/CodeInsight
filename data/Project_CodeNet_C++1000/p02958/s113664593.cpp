#include<iostream>
using namespace std;

int main()
{
    int n, count=0;
    cin>>n;
    int ar[n];
    
    for(int i = 1;i <= n; i++)
    {
        cin>>ar[i];
        if(ar[i]!=i)
        {
            count++;
        }
    }
    if(count==0 || count==2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}