#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int>p,m;
    p.push_back(a[n-1]);
    m.push_back(a[0]);
    for(int i=1; i<n-1; ++i){
        if(a[i]<0)m.push_back(a[i]);
        else p.push_back(a[i]);
    }
    vector<P>ans;
    for(int i=1; i<p.size(); ++i){
        ans.push_back(P(m[0],p[i]));
        m[0]-=p[i];
    }
    for(int i=0; i<m.size(); ++i){
        ans.push_back(P(p[0],m[i]));
        p[0]-=m[i];
    }
    cout<<p[0]<<endl;
    rep(i,ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}