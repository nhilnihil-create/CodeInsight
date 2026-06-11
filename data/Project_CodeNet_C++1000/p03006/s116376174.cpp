#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
using graph = std::vector<std::vector<long long>>;
int main(){
    int N;
    cin >> N;
    ll x[N];
    ll y[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    map<pair<ll,ll>,ll> m;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            m[make_pair(x[i]-x[j],y[i]-y[j])]++;
        }
    }
    auto begin = m.begin(), end = m.end();
    ll M = 0;
    for (auto iter = begin; iter != end; iter++) {
        // first: key, second: value
       // cout << "key = " << (iter->first).first << "\n";
        //cout << "value = " << iter->second << "\n";
        if(iter->first.first == 0 && iter->first.second == 0){
            continue;
        }
        if(M < iter -> second){
            //cout << "update" << iter -> first.first << "," << iter -> first.second << endl;
        }
        M = max(M,iter->second);
    }
    cout << N - M  << endl;
}