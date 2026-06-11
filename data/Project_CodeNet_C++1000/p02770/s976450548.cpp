//
//  main.cpp
//  ABC156F
//
#define rep(i,n) for(int i=0;i<(n);++i)
#include <iostream>
#include<vector>
using namespace std;
using ll= long long;

int main(int argc, const char * argv[]) {
    int k,q;
    cin>>k>>q;
    vector<int> d(k);
    rep(i,k) cin>>d.at(i);
    rep(qi,q){
        int n,x,m;
        cin>>n>>x>>m;
        ll last=x;
        ll eq=0;
        rep(i,k){
            ll num=(n-1-i+k-1)/k;
            last += (d.at(i)%m)*num;
            if(d.at(i)%m==0) eq +=num;
        }
        ll ans=n-1-last/m+x/m-eq;
        cout << ans<<endl;
    }
    return 0;
}
