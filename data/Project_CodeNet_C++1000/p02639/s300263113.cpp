#include<iostream>
typedef long long ll;

using namespace std;

int main()
{
    ll a[6],i;
    for(i=1; i<=5; i++)
        cin>>a[i];
    for(i=1; i<=5; i++)
    {
        if(a[i]==0)
        {
            cout<<i<<endl;
            break;
        }
    }
}


