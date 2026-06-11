//JI SRI KRISHNA.//
#include<iostream>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,c=1,d,mini;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            if(a[i]<=mini)
            {
                c++;
                mini=a[i];
            }
        }
        else
        {
            mini=a[i];
        }

    }
    cout<<c<<endl;

}
