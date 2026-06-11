#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

int main(){
    int n; cin >> n;
    vector<pair<ll, ll>> p(n);
    for(int i=0; i<n; i++){
        ll a,b; cin >> a >> b;
        p[i]=make_pair(b,a);
    }
    sort(p.begin(), p.end());
    ll asum=0;
    ll limit=0;
    for(int i=0; i<n; i++){
        asum += p[i].second; limit = p[i].first;
        if(limit<asum){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}