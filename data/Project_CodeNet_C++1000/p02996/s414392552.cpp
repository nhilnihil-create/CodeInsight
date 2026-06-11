#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main(){
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i,n)cin >> a[i].second >> a[i].first;
    ll time = 0;
    sort(a.begin(),a.end());

    rep(i,n){
        time+=a[i].second;
        //cout << a[i].first<<" "<<a[i].second << endl;
        if(time > a[i].first){
            cout << "No" << endl;
            return 0;
        }
        
    }
    cout <<"Yes" << endl;
    return 0;
}