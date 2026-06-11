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
    int n;
    cin>>n;
    vector<int> p(n);
    rep(i,n){
        cin>>p.at(i);
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        if((p.at(i-1)-p.at(i))*(p.at(i)-p.at(i+1))>0){ans++;}
    }
    cout<<ans<<endl;
}