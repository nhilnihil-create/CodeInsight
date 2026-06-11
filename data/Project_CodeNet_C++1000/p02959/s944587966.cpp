#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> b(n);
    rep(i,n+1) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);
    ll total = 0;
    rep(i,n+1) total += a.at(i);
    rep(i,n){
        if(a.at(i) >= b.at(i)){
            a.at(i) -= b.at(i);
            b.at(i) = 0;
        }else{
            b.at(i) -= a.at(i);
            a.at(i) = 0;
            a.at(i+1) = max(a.at(i+1) - b.at(i),0);
        }
    }
    ll remain = 0;
    rep(i,n+1) remain += a.at(i);
    cout << total - remain << endl;
}