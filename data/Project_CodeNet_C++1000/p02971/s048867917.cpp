#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    sort( a , a+n);
    ll max = a[n-1];
    ll countmax =0;
    ll second = 0;
    for(int i=n-1;i>=0;i--)
    {
        if( a[i] != max)
        {
            second = a[i];
            break;
        }
        else countmax++;
    }
    for(int i =0;i<n;i++ )
    {
        if( b[i] == max) {
            if( countmax > 1)
                cout<<max<<endl;
            else if( second !=0)
            cout << second << endl;
            else cout<<max<<endl;
        }
        else cout<<max<<endl;

    }
}
