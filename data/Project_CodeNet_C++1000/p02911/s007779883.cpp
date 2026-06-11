#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n , k, q;
    cin>>n>>k>>q;
    ll* a = new ll[n]();
    for(int i=0;i<q;i++)
    {
        int temp ;
        cin>>temp;
        temp--;
        a[temp] ++;
    }

    for(int i=0;i<n;i++)
    {
        if( a[i] + k -q >0   )
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}