#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n,q;
    ll k;
    cin >> n >> k >> q;
    vector<int> a(q);
    rep(i,q) cin >> a.at(i);
    vector<ll> score(n,0);
    rep(i,q) score.at(a.at(i)-1)++;
    rep(i,n){
        if(q-score.at(i)>=k) cout << "No" << endl;
        else cout << "Yes" << endl;
    }


}
    
    