#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n,m;
    cin >> n>>m;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    ll sum = 0;
    rep(i,n)sum+=a[i];
    double x =1.0/(m*4.0);
    double y = sum*x;
    int ans = 0;
    rep(i,n){
        if((int)ceil(y)<=a[i]){
            ans++;
        }
    }
    if(ans>=m){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;

}