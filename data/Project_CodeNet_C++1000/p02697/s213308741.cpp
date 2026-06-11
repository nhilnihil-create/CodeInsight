#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> ans;
    if(n&1){
        for(int i=0;i<(n-1)/2;i++){
            ans.emplace_back(i+2,-i+n);
        }
    }
    else{
        int k=0;
        for(int i=0;n/2-2*i-1>0;i++){
            ans.emplace_back(i+1,-i+n);
            k++;
        }
        for(;k<(n-2)/2;k++){
            ans.emplace_back(k+2,-k+n);
        }
    }

    for(int i=0;i<m;i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}