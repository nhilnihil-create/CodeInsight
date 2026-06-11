#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    cin>>n;
    double a,sum=0;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        sum+=1.0/a;
    }
    cout<<1.0/sum<<endl;
    exit(0);
}
