#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int state[1 << 13];

int main(){
    int n,m;
    cin >> n >> m;
    int INF = 1e9;
    rep(i,1<<13){
        state[i] = INF;
    }
    state[0] = 0;
    int a,b;
    int c,pos;
    rep(i,m){
        cin >> a >> b;
        c = 0;
        rep(j,b){
            cin >> pos;
            pos--;
            c += (1 << pos);
        }
        rep(i,1<<n){
            state[i|c] = min(state[i | c],state[i]+a);
        }
    }
    if(state[(1<<n)-1] == INF){
        cout << -1 << endl;
        return 0;
    }
    
    cout << state[(1<<n)-1] << endl;
    return 0;
}