#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    
    vector<pair<int,int>> ans;
    
    int left=1,right=N;
    while(left<right){
        int sh=N%2==0&&right-left<=N/2;
        ans.push_back(make_pair(left+sh,right));
        ++left;
        --right;
    }
    
    for(int i=0;i<M;++i){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
