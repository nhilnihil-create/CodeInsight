#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    while(true){
        cin>>n>>m;
        if(n==0&&m==0)break;
        vector<pair<int,int>> e;
        for (int i = 0; i < n; ++i) {
            int a,b;
            cin>>a>>b;
            e.emplace_back(b,a);
        }
        sort(e.rbegin(),e.rend());
        long long ans=0;
        for (int i = 0; i < n; ++i) {
            if(m<=0)ans+=e[i].first*e[i].second;
            else {
                if(e[i].second<=m){
                    m-=e[i].second;
                    e[i].second=0;
                }
                else{
                    e[i].second-=m;
                    m=0;
                    ans+=e[i].first*e[i].second;
                }
            }
        }
        cout<<ans<<endl;
    }
}
