#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define B begin()
#define E end()
using namespace std;
int main()
{
    ll n,k; cin>>n>>k;
    if(k<(n*2) || k>(n*4) || k%2) cout<<"No";
    else cout<<"Yes";
}
