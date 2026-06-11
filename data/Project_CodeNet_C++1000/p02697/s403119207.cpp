#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main(){
    ll n,m;cin >>n>>m;
    if(m%2==0){
        ll l=1,r=m;
        for (int i = 1; i <=m/2 ; ++i) {
            cout <<l<<" "<<r<<endl;
            l++;r--;
        }
        l=m+1;r=2*m+1;
        for (int i = 1; i <=m/2 ; ++i) {
            cout <<l<<" "<<r<<endl;
            l++;r--;
        }
    }
    if(m%2==1){
        ll l=1,r=m;
        for (int i = 1; i <=m/2 ; ++i) {
            cout <<l<<" "<<r<<endl;
            l++;r--;
        }
        l=m+1;r=2*m+1;
        for (int i = 1; i <=(m+1)/2 ; ++i) {
            cout <<l<<" "<<r<<endl;
            l++;r--;
        }
    }
    return 0;
}