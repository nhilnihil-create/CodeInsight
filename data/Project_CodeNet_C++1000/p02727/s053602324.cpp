#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<int>red(a),green(b),less(c);
    for(auto& i:red)cin>>i;
    for(auto& i:green)cin>>i;
    for(auto& i:less)cin>>i;
    sort(red.rbegin(),red.rend());
    sort(green.rbegin(),green.rend());
    red.erase(red.begin()+x,red.end());
    green.erase(green.begin()+y,green.end());
    for(auto i:green)
    red.push_back(i);
    for(auto i:less)
    red.push_back(i);
    sort(red.rbegin(),red.rend());
    ll sum=0;
    for(int i=0;i<x+y;i++)
    sum+=red[i];
    cout<<sum<<endl;
}
