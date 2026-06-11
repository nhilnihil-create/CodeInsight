#include<iostream>
using namespace std;
int main()
{
    int n,m,s=0;
    cin>>n>>m;
    int ar[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        s+=ar[i];
    }
    double k = 1.0*s/(m*4);
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(ar[i]>=k)
            c++;
    }
    if(c>=m)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
