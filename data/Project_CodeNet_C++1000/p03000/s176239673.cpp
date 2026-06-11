#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> L(n);
    rep(i,n) cin >> L[i];
    int d=0 ,cnt=1;
    rep(i,n){
        int p=d+L[i];
        if(p<=x)cnt++;
        d=p;
    }
    cout << cnt << endl;
    return 0;
}
