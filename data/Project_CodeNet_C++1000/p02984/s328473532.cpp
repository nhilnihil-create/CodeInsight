#include <iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n) cin>>a[i];
    ll x0 = 0;
    rep(i,n){
        if(i%2) x0 -= a[i];
        else x0 += a[i];
    }
    vector<int>ans(n);
    ans[0] = x0/2;
    rep(i,n-1){
        ans[i+1] = a[i]-ans[i];
    }
    rep(i,n) cout<<2*ans[i]<<" ";

    return 0;
}