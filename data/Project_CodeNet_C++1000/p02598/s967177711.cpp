#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k; 
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ng = 0, ok = 1e9;
    auto isOK = [&](int x){
        int now = 0;
        rep(i,n) now += (a[i] - 1) / x;
        return now <= k;
    };
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if(isOK(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}