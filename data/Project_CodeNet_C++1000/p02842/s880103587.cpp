#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    double m=x/1.08;
    ll first=m,second=m+1;
    ll f=first*1.08;
    ll s=second*1.08;
    if (f==x)
        cout<<first;
    else if (s==x)
        cout<<second;
    else
        cout<<":(";
    return 0;
}
