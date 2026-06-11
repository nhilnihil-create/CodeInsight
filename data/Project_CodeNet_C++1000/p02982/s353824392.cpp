#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    vector<vector<float>> t(n,vector<float>(d,0));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<d;++j){
            cin>>t[i][j];
        }
    }
    int ans = 0,dist;
    for(int i = 0;i<n-1;++i){
        for(int j = i+1;j<n;++j){
            dist = 0;
            for(int k = 0;k<d;++k){
                dist += (t[i][k]-t[j][k])*(t[i][k]-t[j][k]);
            }
            if(dist == (int)sqrt(dist)*sqrt(dist)){
                ans++;
            }
        }   
    }
    cout<<ans;
    return 0;
}