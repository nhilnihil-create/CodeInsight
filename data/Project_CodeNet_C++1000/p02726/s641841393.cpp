#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll=long long;

int n,m;
vector<vector<int>> dat(1000000);
vector<int> ans(10000000);

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    rep(i,n){
        for(int j=i+1;j<=n;j++){
            int m=j-i;
            ans[min(j-i,abs(i-x)+abs(j-y)+1)]++;

        }
    }
    rep(i,n-1){
        cout<<ans[i]<<endl;
    }
    return 0;
}