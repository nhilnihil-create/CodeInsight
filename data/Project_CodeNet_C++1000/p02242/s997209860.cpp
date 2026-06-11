#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <algorithm>
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<n;i++)
vector<bool> seen;
int main(){
    int N,t;
    cin >> N;
    vector<int> costs(N);
    vector<vector<P>> T(N,vector<P>(N));
    vector<int> v(N);
    vector<int> ved(N);
    P pa;
    rep(i,N){
       cin >> t;
       cin >> v[i];
       rep(j,v[i]){
           cin >> T[i][j].second >> T[i][j].first;
       }
       sort(T[i].begin(),T[i].begin()+v[i]);
    }
    seen.assign(N, false);
    costs.assign(N,1e9);
    seen[0] = true;
    costs[0] = 0;
    rep(i,N-1){
        pa.first = 1e9;
        rep(j,N){
            rep(k,v[j]){
                if(seen[T[j][k].second])continue;
                if(pa.first > costs[j]+T[j][k].first){
                    pa.first = costs[j]+T[j][k].first;
                    pa.second = T[j][k].second;
                }
            }
        }
        seen[pa.second] = true;
        costs[pa.second] = pa.first;
    }
    rep(i,N){
        cout << i << " " << costs[i] << endl;
    }
    return 0;
}
