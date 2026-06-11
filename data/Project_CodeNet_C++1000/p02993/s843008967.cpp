#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    string S;
    cin>>S;
    rep(i,3){
        if(S.at(i)==S.at(i+1)){cout<<"Bad"<<endl;return 0;}
    }
    cout<<"Good"<<endl;
}