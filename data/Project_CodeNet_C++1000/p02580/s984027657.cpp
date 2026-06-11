#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};

int main(){
    int h,w,m;cin>>h>>w>>m;
    vector<int> hs(h,0),ws(w,0);
    set<P> s;
    rep(i,m){
        int c,r;cin>>c>>r;
        --c;--r;
        hs[c]++;ws[r]++;
        s.emplace(c,r);
    }
    vector<int>is,js;
    int mi=0,mj=0;
    rep(i,h)mi = max(mi,hs[i]);
    rep(j,w)mj = max(mj,ws[j]);
    rep(i,h)if(mi == hs[i])is.emplace_back(i);
    rep(j,w)if(mj == ws[j])js.emplace_back(j);

    int ans = mi + mj;
    for(int i : is)for(int j : js){
        if(s.count(P(i,j)))continue;
        cout<<ans<<endl;
        return 0;
    }
    ans--;
    cout<<ans<<endl;
    
    return 0;
}