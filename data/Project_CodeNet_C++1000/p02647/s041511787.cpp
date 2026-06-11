#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long int ll;

#define PI (acos(-1))
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define dumparr(x) cerr << #x ; for(auto elem: x){cerr << " " << elem;} cerr << endl;
#define dumppairs(x) cerr << #x ; for(auto elem: x){cerr << "(" << elem.first << " " << elem.second << ") ";} cerr << endl;
#define dumpline cerr << "**********************" << endl;
#define dumpwline(x) cerr << "******** " << #x << "=" << (x) << " ********" << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main(void){
    ll n; cin >> n;
    ll k; cin >> k;
    vector <ll> as;
    REP(i, n){
        ll a; cin >> a;
        as.push_back(a);
    }
    REP(_, min(k, ll(50))){
        vector <ll> imos(n+1, 0);
        REP(i, n){
            imos[max(i-as[i], ll(0))]++;
            imos[min(1+i+as[i], ll(n))]--;
        }
        ll cnt = 0;
        REP(i, n){
            cnt += imos[i];
            as[i] = cnt;
        }
    }
    REP(i, n-1){
        cout << as[i] << " ";
    }
    cout << as[n-1] << endl;
    return 0;
}
