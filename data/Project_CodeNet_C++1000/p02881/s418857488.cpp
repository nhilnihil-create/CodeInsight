#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,p=0,q=0,min=1000000000000;
    cin>>n;
    for(i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            p=i;
            q=n/i;
            if((p+q-2)<min)
                min=p+q-2;
        }
    }
    //cout<<p<<" "<<q<<endl;
    cout<<min;
    return 0;
}
