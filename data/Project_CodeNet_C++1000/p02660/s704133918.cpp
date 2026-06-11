#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <list>


#define REP(i, n ,N) for(ll i = (n); i < (N); i++)
//#define RREP(i, n ,N) for(ll i = (N-1); i >= (n); i--)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
#define vint vector<int>
#define INF 1e9

using namespace std;
typedef long long  ll;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
    ll n;
    cin >> n;
    const auto &res = prime_factorize(n);
//    cout << n << ":";
    ll ans = 0;
    for (auto p : res) {
//        for (int i = 0; i < p.second; ++i) cout << " " << p.first;
        ll used = 0;
        ll cnt = 1;
        do{
            ans += 1;
            used += cnt;
            cnt += 1;
        }while (p.second >=  used + cnt);
    }
    p(ans);
}