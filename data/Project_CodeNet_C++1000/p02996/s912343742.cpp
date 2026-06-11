#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> limit;
    for(int i=0; i<n; i++){
        ll a,b;
        cin >> a >> b;
        pair<ll, ll> p = make_pair(b,a);
        limit.push_back(p);
    }
    sort(limit.begin(), limit.end());
    bool possible = true;
    ll count = 0;
    for(int i=0; i<n; i++){
        pair<ll, ll> q;
        q = limit.at(i);
        count += q.second;
        if(count > q.first){
            possible = false;
            break;
        }
    }
    if(possible) cout << "Yes" << endl;
    else cout << "No" << endl;
}
