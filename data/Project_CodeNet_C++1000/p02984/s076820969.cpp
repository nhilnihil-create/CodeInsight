#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0;i<n;i++)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (b>a) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 2LL << 60;
using ll = long long;
using P = pair<ll, ll>;
int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> x(n);
    rep(i, n) cin >> a[i];
    rep(i, n){
        if(i%2==0)  x[0]+=a[i];
        else        x[0]-=a[i];
    }
    x[0]/=2;
    rep(i,n-1){
        x[i+1]=a[i]-x[i];
    }
    rep(i, n){
        cout << x[i]*2 << endl;
    }
    return 0;
}


