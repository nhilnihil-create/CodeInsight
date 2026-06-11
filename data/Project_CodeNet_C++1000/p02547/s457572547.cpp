#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

void solve()
{
 int n;
 cin>>n;
 vector<pair<int,int> >v;
 for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,b});
 }
       int f=0;
   for(int i=0;i<v.size()-2;i++){
    if(v[i].first==v[i].second&&v[i+1].first==v[i+1].second&&v[i+2].first==v[i+2].second){f=1;break;}
 }
 if(f){cout<<"Yes"<<endl;}
 else cout<<"No"<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

        solve();

    return 0;
}

