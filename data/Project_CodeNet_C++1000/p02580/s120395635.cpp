#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,b;
    cin>>h>>w>>b;
    unordered_map<int,int> xtrack;
    unordered_map<int,int> ytrack;
    map<pair<int,int>,int>coor;
    for(int i=1;i<=b;i++){
        int x,y;
        cin>>x>>y;
        coor[make_pair(x,y)]=1;
        xtrack[x]++;
        ytrack[y]++;
    }
    int xmax=INT_MIN;
    int ymax=INT_MIN;
    for(auto i:xtrack){
        xmax=max(xmax,i.second);
    }
    for(auto j:ytrack){
        ymax=max(ymax,j.second);
    }
    vector<int> xcan;
    vector<int> ycan;
    for(auto i:xtrack){
        if(i.second==xmax){
            xcan.push_back(i.first);
        }
    }
    for(auto j:ytrack){
        if(j.second==ymax){
            ycan.push_back(j.first);
        }
    }
    int ans=xmax+ymax-1;
    for(int i=0;i<(int)xcan.size();i++){
        for(int j=0;j<(int)ycan.size();j++){
            if(coor[make_pair(xcan[i],ycan[j])]==0){
                    ans=xmax+ymax;
                    break;
            }
        }
    }
    cout<<ans;
    return 0;
}