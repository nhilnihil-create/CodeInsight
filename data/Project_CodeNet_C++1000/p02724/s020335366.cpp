#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll ans=(n/500)*1000+((n%500)/5)*5;
    cout<<ans<<endl;
}