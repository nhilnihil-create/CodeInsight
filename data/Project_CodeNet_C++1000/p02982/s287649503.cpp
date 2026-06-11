#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
 
int main(){
    int n,d;cin>>n>>d;
    vector<vector<int>> x(n,vector<int>(d));
    rep(i,n){
        rep(j,d)cin>>x[i][j];
    }
    int ans=0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            int dis=0;
            rep(k,d){
                dis+=pow(x[i][k]-x[j][k],2);
            }
            double sq=sqrt(dis);
            //cout<<d<<" "<<sq<<endl;
            if(sq==(int)sq)ans++;
        }
    }
    cout<<ans<<endl;
}