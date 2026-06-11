#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <map>
using namespace std;
#define DEB(variable) cout << #variable << '=' << variable << endl

#define FOR(LoopVariable, numberOFbegin, numberOFend) for(long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable, numberOFbegin, numberOFend) for(long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable, numberOFend) for(long long int LoopVariable = 0; (LoopVariable) < (numberOFend); LoopVariable++)

using llint = long long int;

constexpr long long int linf = numeric_limits<long long int>::max() - 5;
constexpr long long int inf = numeric_limits<int>::max() - 5;
constexpr long long int mod = 1000000007;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    llint n;
    cin >> n;
    vector<llint>v(n);
    REP(i,n){
        cin >> v[i];
    }
    if(v[0]!=0){
        cout << 0 << endl;
    }else{
        llint result = 1;
        map<llint, llint> mp;
        FOR(i,0,n){
            mp[v[i]]++;
        }
        if(mp[0]!=1){
            cout << 0 << endl;
        }else{
            llint num =mp[0];
            FOR(i,1,n){
                if(mp[i]==0){
                    break;
                }
                result *= (llint)modpow(mp[i - 1] , mp[i],998244353);
                num += mp[i];
                result %=998244353 ;
            }
            if(n==num){
                cout << result << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
}
