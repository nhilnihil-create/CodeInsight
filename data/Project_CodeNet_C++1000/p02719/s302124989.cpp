#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){


    ll n,k;
    cin>>n>>k;
    ll x=n%k;
    if(x>k/2)
    {
        x=k-x;
    }
    cout<<x<<endl;

}
