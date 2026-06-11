/*
                   _ooOoo_
                  o8888888o
                  88" . "88　AC!AC!
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rep3(var, min, max) for (ll (var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll (var) = (max) - 1; (var) + 1 > (min); --(var))
#define Mp(a,b) make_pair((a),(b))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll MOD = 1e9 + 7;
int main(){
    ll n;cin>>n;
    VP vec(n);
    rep(i,n){
        ll x,y;cin>>x>>y;
        vec[i]=Mp(x,y);
    }
    map<P,ll> res;
    ll Max=0;
    sort(all(vec));
    rep(i,n){
        rep3(j,i+1,n){
            if(vec[i].first-vec[j].first==0&&vec[i].second-vec[j].second==0)continue;
            //cout<<vec[i].first-vec[j].first<<" "<<vec[i].second-vec[j].second<<endl;
            res[Mp(vec[i].first-vec[j].first,vec[i].second-vec[j].second)]++;
            chmax(Max,res[Mp(vec[i].first-vec[j].first,vec[i].second-vec[j].second)]);
        }
    }
   // cout<<Max<<endl;
    cout<<n-Max<<endl;
}
