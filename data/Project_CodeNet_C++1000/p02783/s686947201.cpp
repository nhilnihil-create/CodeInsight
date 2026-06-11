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
    int a,b;
    cin>>a>>b;
    cout<<ceil((1.0*a)/b);
}