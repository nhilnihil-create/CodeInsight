#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll a = n/500;
    n-=a*500;
    ll b = n/5;
    cout<<a*1000 + b*5;
    return 0;
}
