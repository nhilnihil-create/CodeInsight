#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int h,w,m;
    cin>>h>>w>>m;
    vector<int> y(m),x(m);
    map<pair<int,int>,int> bomb;
    for(int i=0; i<m; i++){
        cin>>y[i]>>x[i];
        y[i]--;
        x[i]--;
        bomb[make_pair(y[i],x[i])]++;
    }
    
    map<int,int> ycnt,xcnt;
    for(int i:y) ycnt[i]++;
    for(int i:x) xcnt[i]++;

    vector<pair<int,int>> yp,xp;
    for(auto i:ycnt) yp.push_back(make_pair(i.second,i.first));
    for(auto i:xcnt) xp.push_back(make_pair(i.second,i.first));
    sort(yp.begin(),yp.end(),greater<>());
    sort(xp.begin(),xp.end(),greater<>());

    int ans = yp[0].first+xp[0].first;
    if(bomb[make_pair(yp[0].second,xp[0].second)]){
        ans--;
        for(auto i:yp){
            if(bomb[make_pair(i.second,xp[0].second)]){
                ans = max(ans, i.first+xp[0].first-1);
            }else{
                ans = max(ans, i.first+xp[0].first);
            }
        }
        for(auto i:xp){
            if(bomb[make_pair(yp[0].second,i.second)]){
                ans = max(ans, yp[0].first+i.first-1);
            }else{
                ans = max(ans, yp[0].first+i.first);
            }
        }
    }
    cout<<ans<<endl;
}