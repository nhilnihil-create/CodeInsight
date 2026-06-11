#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long a,b,k;
    cin>>a>>b>>k;
    if(k<=a)
    {
        cout<<(a-k)<<" "<<b<<endl;
    }
    else
    {
        if((k-a)>=b)
        {
            b=0;
        }
        else
        {
            b=b-(k-a);
        }
        cout<<"0 "<<b<<endl;
    }
    return 0;
}