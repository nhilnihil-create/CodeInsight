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
    ll n; cin>>n;
    vector<ll> v(n);
    ll ans=1;
    REP(i,n){cin>>v[i];if(v[i]==0){cout<<0<<endl;return 0;}}
    sort(ALL(v),greater());
    REP(i,n){
        if(v[i]<=1000000000000000000/ans)ans*=v[i];
        else{ans=-1;break;}
    }
    cout<<ans<<endl;
    return 0;
}
