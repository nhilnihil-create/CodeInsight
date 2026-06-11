#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve()
{
    vector<pair<int,pair<int,int>>>v;
    rep(i,1,200)rep(j,i+1,200){
        v.push_back({i*i+j*j,{i,j}});
    }
    sort(v.begin(),v.end());
    int i,j;
    while(cin>>i>>j && i!=0){
        auto res=find(v.begin(),v.end(),make_pair(i*i+j*j,make_pair(i,j)));res++;
        cout<<res->second.first<<" "<<res->second.second<<endl;;
    }
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}

