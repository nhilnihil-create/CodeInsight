#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(int)(n);i++)
using namespace std;
using p=pair<int,int>;


int main(){
    int h,w,n;
    cin>>h>>w>>n;
    vector<int> row(h),col(w);
    set<p> map;
    rep(i,n){
        int r,c;
        cin>>r>>c;
        r--;c--;
        row[r]++;col[c]++;
        map.emplace(r,c);
    }

    int mr=0;int mc=0;
    rep(i,h)mr=max(mr,row[i]);
    rep(i,w)mc=max(mc,col[i]);
    vector<int> is,js;
    rep(i,h)if(mr==row[i])is.push_back(i);
    rep(j,w)if(mc==col[j])js.push_back(j);

    int ans=mr+mc;

    for(int i:is)for(int j:js){
        if(map.count(p(i,j)))continue;
        cout<<ans<<endl;
        return 0;
    }

    ans--;
    cout<<ans<<endl;
    return 0;


    
}