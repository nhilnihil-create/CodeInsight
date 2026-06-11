#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
ll n,k;
bool is_able_to_cut(ll x,vector<ll> a){
    ll total = 0;
    if(x == 0){
        return true;
    }
    REP(i,a.size()){
        total+=(a[i]-1)/x;
    }
    return k >= total;
}

ll BinarySearch(vector<ll>a){
    ll ng=0,ok = 1000000000;
    while(llabs(ok-ng) > 1){
        ll mid = (ng+ok)/2;
        if(is_able_to_cut(mid,a)){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    return ok;
}

int main(){
    cin >> n >> k;
    vector<ll>a(n);
    REP(i,n)cin >> a[i];
    if(k==0){
        SORT(a);
        reverse(ALL(a));
        cout << a[0] << endl;
        return 0;
    }
    cout << BinarySearch(a) << endl;
    return 0;
}