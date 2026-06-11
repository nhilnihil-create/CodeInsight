#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m,q;cin>>n>>m>>q;
    vector<int> a(q+1),b(q+1),c(q+1),d(q+1);

    for(int i=1;i<=q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    queue<vector<int>> qq;
    qq.push({1});
    int ans=0;
    while(qq.size()){
        vector<int> v=qq.front();qq.pop();
        if(v.size()==n+1){
            int res=0;
            for(int i=1;i<=q;i++){
                if(v[b[i]]-v[a[i]]==c[i]){
                    res+=d[i];
                }
            }
            ans=max(ans,res);
        }
        else{
            for(int i=v.back();i<=m;i++){
                v.emplace_back(i);
                qq.push(v);
                v.pop_back();
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
