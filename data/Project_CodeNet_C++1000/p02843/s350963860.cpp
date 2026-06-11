#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int X; cin>>X;

    vector<int> dp(X+1,0),P{100,101,102,103,104,105};
    dp.at(0)=1;

    rep(x,0,X){
        if(dp.at(x)){
            for(auto p:P){
                if(x+p<X+1) dp.at(x+p)=1;
            }
        }
    }

    cout<<dp.at(X)<<endl;
}