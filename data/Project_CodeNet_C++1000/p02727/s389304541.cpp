#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

int32_t main()
{

    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<int> red(a);for(auto &i:red)cin>>i;
    vector<int> gre(b);for(auto &i:gre)cin>>i;
    vector<int> col(c);for(auto &i:col)cin>>i;
    sort(red.rbegin(),red.rend());
    sort(gre.rbegin(),gre.rend());
    for(int i=0;i<x;i++)col.push_back(red[i]);
    for(int i=0;i<y;i++)col.push_back(gre[i]);
    sort(col.rbegin(),col.rend());

    int ans=accumulate(col.begin(),col.begin()+x+y,0LL);
    cout<<ans;



}
