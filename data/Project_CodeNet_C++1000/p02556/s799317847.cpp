#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

ll solve(vector<int> x,vector<int> y)
{
    int mn=INT_MAX,mx=INT_MIN;
    int mn2=INT_MAX,mx2=INT_MIN;
    int max_i=0,min_i=0;
    for(int i=0;i<n;i++)
    {
    mn = min(mn,(x[i]+y[i]));
    mx = max(mx,(x[i]+y[i]));
    mn2 = min(mn2,(x[i]-y[i]));
    mx2 = max(mx2,(x[i]-y[i]));      
    }
    //cout<<mn<<" "<<mx<<" "<<mn2<<" "<<mx2<<" ";
    return max(abs(mx2-mn2),abs(mx-mn));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> x(n,0),y(n,0);
    for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
    cout<<solve(x,y);
    return 0;
}