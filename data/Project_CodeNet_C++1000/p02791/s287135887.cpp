#include<iostream>
using namespace std;
int main()
{
    long long int N,i,s,c;
    cin>>N;
    int a[N];
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }
    s=a[0],c=1;
    for(i=1;i<N;i++)
    {
        if(a[i]<=s)
        {
            c++;
            s=a[i];
        }
    }
    cout<<c<<endl;

}
