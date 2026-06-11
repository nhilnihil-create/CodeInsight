#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]==a[1]&&a[0]!=a[2])
    cout<<"Yes"<<endl;
    else if(a[0]==a[2]&&a[0]!=a[1])
    cout<<"Yes"<<endl;
    else if(a[2]==a[1]&&a[0]!=a[2])
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

    return 0;
}


