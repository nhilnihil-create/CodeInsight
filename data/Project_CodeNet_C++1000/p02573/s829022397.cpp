#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;

using namespace std;

ll n, m, k;
ll h, w;
ll solve(ll cm, int i, map<ll, vector<ll> >& abm, vector<bool>& ckd, vector<ll>& clst){
    if(ckd[i]) return 0;
    clst[i] = cm;
    ckd[i] = true;
    for(auto it = abm[i].begin(); it != abm[i].end(); ++it){
        solve(cm, *it, abm, ckd, clst);
    }
    return 0;
}

int main(){
    cin >> n >> m;
    map<ll, vector<ll> > abm;
    for (int i=0; i<m; ++i){
        ll a, b;
        cin >> a >> b;
        abm[a-1].push_back(b-1);
        abm[b-1].push_back(a-1);
    }
    vector<bool> ckd(n,false);
    vector<ll> clst(n);
    for(int i=0; i<n; ++i)clst[i] = i;
    for(int i=0; i<n; ++i){
        solve(i,i, abm, ckd, clst);
    }
    map<ll, ll> resm;
    for(auto c : clst){
        resm[c] += 1;
    }
    auto res = max_element(resm.begin(), resm.end(), [](auto a, auto b){return a.second < b.second;});
    cout << res->second << endl;
    return 0;
}