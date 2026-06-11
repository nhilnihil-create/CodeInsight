#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
    ll n ; cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a.at(i);        
    }
    sort(a.begin(),a.end());
    ll x = a.at(0);
    ll y = a.at(n-1);
    vector<pair<ll,ll>> op;

    ll mxm;

    if(x>=0){
        ll m = a.at(0);
        for(int i=1;i<n-1;i++){
            op.push_back(make_pair(m,a.at(i)));
            m = m - a.at(i);
        }
        op.push_back(make_pair(a.at(n-1),m));
        mxm = a.at(n-1) - m;
    }else if(y<0){
        ll m = a.at(n-1);
        for(int i=0;i<n-1;i++){
            op.push_back(make_pair(m,a.at(i)));
            m = m - a.at(i);
        }
        mxm = m;
    }else{
        ll m = a.at(0);
        auto it = lower_bound(a.begin(),a.end(),0);
        ll start = it - a.begin();
        for(int i=start;i<n-1;i++){
            op.push_back(make_pair(m,a.at(i)));
            m = m - a.at(i);
        }
        op.push_back(make_pair(a.at(n-1),m));
        m = a.at(n-1) - m;
        for(int i=1;i<start;i++){
            op.push_back(make_pair(m,a.at(i)));
            m = m - a.at(i);
        }
        mxm = m;
    }
    cout << mxm << endl;
    for(auto i:op){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}