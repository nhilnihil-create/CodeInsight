#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e10
typedef long long ll;
typedef long double ld;
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> h(n+1);
    REP(i,n)cin>>h[i+1];
    vector<vector<ll>> heights(n+1);
    REP(i,m){
        ll a,b;
        cin>>a>>b;
        heights[a].push_back(h[b]);
        heights[b].push_back(h[a]);
    }
    ll cnt=0;
    FOR(i,1,n+1){
        if(SIZE(heights[i])!=0){
            ll highest=MAX(heights[i]);
            if(highest<h[i])cnt++;
        }else{
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
