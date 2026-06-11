#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

int main(){
    long long h,w,m;
    cin>>h>>w>>m;

    vector<int> height(300010,0);
    vector<int> width(300010,0);
    
    vector<pair<int,int>> bombers;
    rep(i,m){
        int h1,w1;
        cin>>h1>>w1;
        height[h1]++;
        width[w1]++;
        bombers.push_back(make_pair(h1,w1));
    }
    int maxh=*max_element(height.begin(),height.end());
    int maxw=*max_element(width.begin(),width.end());
    //cout<<"maxs "<<maxh<<" "<<maxw<<endl;
    set<int> treeh;
    set<int> treex;
    for(int i=1;i<=h;i++){
        if(height[i]==maxh){
            treeh.insert(i);
        }
    }
    for(int k=1;k<=w;k++){
        if(width[k]==maxw){
            treex.insert(k);
        }
    }
    int impossible=0;
    for(int i=0;i<m;i++){
        int y=bombers[i].first;
        int x=bombers[i].second;
        if(treeh.find(y)!=treeh.end() && treex.find(x)!=treex.end()){
            impossible++;
        }
    }
    if(impossible<treeh.size()*treex.size()){
        cout<<maxh+maxw<<endl;
    }
    else{
        cout<<maxh+maxw-1<<endl;
    }
    return 0;

}
/*


*/
