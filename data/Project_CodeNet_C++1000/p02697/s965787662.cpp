#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>
#include <cassert>


using namespace std;
#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<n;++i)
#define FOR(i, a, b) for(int i=a;i<b;++i)
#define RREP(i, n) for(int i=n-1;i>=0;--i)
#define RFOR(i, a, b) for(int i=b-1;i>=a;--i)

#define all(x) begin(x),end(x)
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
    os << p.first << " " << p.second;
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

// edit
int mod(int x, int m){
    int ret = x % m;
    if(ret < 0) ret += m;
    return ret;
}

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<P> seg;
    if(N % 2){
        seg.push_back(P(-1,1));
        for(int i = 1; i < M; ++i){
            seg.push_back(P(seg.back().first - 1, seg.back().second + 1));
        }
        for(int i = 0; i < seg.size(); ++i){
            seg[i].first = mod(seg[i].first, N) + 1;
            seg[i].second = mod(seg[i].second, N) + 1;
        }
        for(auto e : seg){
            cout << e << endl;
        }
    }else{
        seg.push_back(P(0, N / 2 - 1));
        while(seg.size() < M && seg.back().second - seg.back().first > 2){
            seg.push_back(P(seg.back().first + 1, seg.back().second-1));
        }
        
        if(seg.size() < M){
            seg.push_back(P(N / 2, N - 2));
            while(seg.size() < M && seg.back().second - seg.back().first > 2){
                seg.push_back(P(seg.back().first + 1, seg.back().second-1));
            }
        }
        
        for(int i = 0; i < seg.size(); ++i){
            seg[i].first = mod(seg[i].first, N) + 1;
            seg[i].second = mod(seg[i].second, N) + 1;
        }
        for(auto e : seg){
            cout << e << endl;
        }
        
    }
    
    
    

}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());

    solve();


    return 0;
}
