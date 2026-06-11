#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e5+5;
vector<PI>ans;
int n,k;
signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    int ma=(n-1)*(n-2)/2;
    if(k>ma){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++){
        ans.push_back({1,i});
    }
    ma-=k;
    for(int i=2;i<=n&&ma;i++){
        for(int j=i+1;j<=n&&ma;j++){
            ans.push_back({i,j});
            ma--;
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<' '<<i.second<<endl;
    }
    return 0;
}
/*

*/
