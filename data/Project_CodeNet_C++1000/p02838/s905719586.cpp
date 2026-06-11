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
int main(){
    ll n;
    cin >> n;
    vector<ll>a(n),bits(61);
    REP(i,61)bits[i] = 0;
    REP(i,n)cin >> a[i];
    REP(i,n){
        REP(j,61){
            if(a[i] & (1ll<<j)){
                bits[j]++;
            }
        }
    }
    ll answer = 0;
    REP(i,61){
        answer=(answer+((1ll<<i)%MOD*(bits[i]*(n-bits[i])%MOD))%MOD)%MOD;
        cerr << answer << endl;
    }
    cout << answer << endl;
    return 0;
}