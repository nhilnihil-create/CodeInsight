#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    vector<vector<char>>c(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            if((i+1)<=b&&(j+1)<=a)c[i][j]='0';
            else if((i+1)>b&&(j+1)>a)c[i][j]='0';
            else c[i][j]='1';
        }
    }
    rep(i,h){
        rep(j,w){
            cout<<c[i][j];
        }
        cout<<endl;
    }
    return 0;
}