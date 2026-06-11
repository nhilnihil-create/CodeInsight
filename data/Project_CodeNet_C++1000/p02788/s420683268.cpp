#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using ll=long long;
using namespace std;

int main(){
    int N,D,A;
    cin>>N>>D>>A;

    vector<pair<int,int>> map;
    int a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        map.push_back({a,b});
    }
    sort(map.begin(),map.end());

    ll ans=0;
    queue<pair<ll,ll>> q;//place,plus
    ll subd=0;

    for(int i=0;i<N;i++){
        while(!q.empty() && q.front().first<=map[i].first){
            subd+=q.front().second;
            //cout<<q.front().first<<" "<<q.front().second<<endl;
            q.pop();
        }
        ll hp=map[i].second+subd;
        if(hp>0){
            ll numBom=(hp+A-1)/A;
            ans+=numBom;
            ll damage=numBom*A;
            ll range=map[i].first+2*D;
            subd-=damage;
            q.push({range+1,damage});
        }
    }
    cout<<ans<<endl;

    return 0;
}