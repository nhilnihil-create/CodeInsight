#include <iostream>
#include <map>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];

    map<pair<int,int>,int> mp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int dx,dy;
            dx = x[j] - x[i];
            dy = y[j] - y[i];
            mp[make_pair(dx,dy)] ++;
        }
    }
    int ans=n;
    for(auto kv: mp){
        ans = min(ans, n - kv.second);
    }
    cout<<ans<<endl;

}