#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool comp1(pair<int,int> &a,pair<int,int> &b)
{
    return a.second>b.second;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll h;
    cin>>h;
    ll q=log2(h);
    ll p=pow(2,q+1)-1;
    cout<<p;
}