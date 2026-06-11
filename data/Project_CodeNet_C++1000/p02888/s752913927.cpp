#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-9;
const ll INF = 2147483647;
#define rep(i, n) rep3(i, 0, n)
#define rep2(i, n) rep3(i, 1, n+1)
#define rep3(i, x, n) for(ll i = x; i < (ll)(n); i++)

template<class T>
void printv(vector<T> v) {
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << ",";
    }
    cout << endl;
}
template<class T>
void printp(vector<pair<T,T>> v) {
    for(auto it = v.begin(); it != v.end(); it++){
        cout << (*it).first << "," << (*it).second << endl;
    }
    cout << endl;
}
template<class T>
void printp(map<T,T> v) {
    for(auto it = v.begin(); it != v.end(); it++){
        cout << (*it).first << "," << (*it).second << endl;
    }
    cout << endl;
}

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
 
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
  int indexes[n];
  for (int i = 0; i < n; i++) indexes[i] = i;
  do {
    f(indexes);
  } while (std::next_permutation(indexes, indexes + n));
}

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
    ll N;
    vector<ll> l(2001);
    cin>>N;
    rep(i,N) cin>>l[i];
    sort(l.begin(), l.begin()+N);
    
    ll res = 0;
    
    //printv(l);
    
    rep(i,N){
        rep3(j,i+1,N){
            ll k = distance(
                l.begin(),
                lower_bound(l.begin(), l.begin()+N, l[i]+l[j])
            );
            //cout << i<< ","<<j<<","; cout<<k<<endl;
            res += (k - (j+1) >= 0) ? k - (j+1) : 0;
        }
    }
    
    cout << res;
}