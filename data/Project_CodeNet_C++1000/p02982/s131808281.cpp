#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,d;
    cin>>n>>d;
    int x[n][d];
    rep(i,n){
        rep(j,d){
            cin>>x[i][j];
        }
    }
    int cnt=0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            double dis=0;
            rep(k,d){
                dis+=pow(x[i][k]-x[j][k],2);
            }
            int a=sqrt(dis);
            a=pow(a,2);
            if(dis==a)cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}