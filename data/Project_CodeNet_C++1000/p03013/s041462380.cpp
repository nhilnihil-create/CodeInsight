/**
*    author:  souzai32
*    created: 12.08.2020 00:16:27
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    vector<long long> f(1e5+1);
    f.at(0)=1;
    f.at(1)=1;
    for(int i=2; i<=1e5; i++){
        f.at(i)=f.at(i-1)+f.at(i-2);
        f.at(i)%=1000000007;
    }
    // rep(i,100) cout << f.at(i) << endl;
    // cout << f.at(0)+f.at(1) << endl;

    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a.at(i);
    int s=0;
    long long ans=1;
    rep(i,m){
        if(a.at(i)==s){
            ans=0;
            break;
        }
        ans*=f.at(a.at(i)-s-1);
        ans%=1000000007;
        s=a.at(i)+1;
    }
    ans*=f.at(n-s);
    ans%=1000000007;

    cout << ans << endl;

    return 0;
}