#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    vector<vector<int>> x(n,vector<int>(d));
    rep(i,n) rep(j,d) cin>>x[i][j];

    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int num=0;
            double dist=0;
            for(int k=0;k<d;k++){
                num+=pow(x[i][k]-x[j][k],2);
            }
            dist=sqrt(num);
            if(ceil(dist)==floor(dist)) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}