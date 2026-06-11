#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    --x; --y;
    vector<int> ans(n,0);
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int cur=abs(i-j);
            cur=min(cur,abs(x-i)+1+abs(y-j));
            cur=min(cur,abs(y-i)+1+abs(x-j));
            ++ans[cur];
        }
    }
    
    for(int i=1;i<n;++i) cout<<ans[i]<<endl;
}