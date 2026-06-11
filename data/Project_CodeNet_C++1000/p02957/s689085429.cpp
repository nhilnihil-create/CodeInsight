#include<bits/stdc++.h>
#define ll long long int


using namespace std;

int main()
{
    ll a,b; cin>>a>>b;
    ll x=a+b;
    if (x&1)cout << "IMPOSSIBLE"<<endl;
    else cout << x/2 <<endl;
    return 0;
}
