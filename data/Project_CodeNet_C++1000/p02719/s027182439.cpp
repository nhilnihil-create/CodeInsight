#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll n,k;
    cin>>n>>k;

    if(k==1||n==k)
        cout<<"0\n";
    else if(n<k)
      cout<<min(n,abs(n-k))<<"\n";
    else
        cout<<min(n%k,k-(n%k))<<"\n";
return 0;
}
