#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    ll n,m;
    cin >> n >> m;
    priority_queue<int> que;
    int tmp;
    rep(i,n){
        cin >> tmp;
        que.push(tmp);
    }
    rep(i,m){
        tmp = que.top();
        que.pop();
        que.push(tmp/2);
    }

    ll ans = 0;
    while(!que.empty()){
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;

    return 0;
}