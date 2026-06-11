#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn =2e5+10;
const int mod=1e9+7;




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>a,b;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        int t=x+y;
        int t2=x-y;
        a.pb(t);
        b.pb(t2);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<max(a.back()-a.front(),b.back()-b.front())<<'\n';







}
