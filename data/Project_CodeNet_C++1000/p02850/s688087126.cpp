/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
#define WOULD
#define YOU
#define PLEASE
#define ACCEPT
#define MY
#define SUBMISSION
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 100100100100;
const long long MOD = 998244353;
typedef pair<int,int> P;

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}
//繋がっている頂点,.secondが辺の番号
vector<vector<P>> Edge(100005);
vector<int> connectedEdge(100005,0);
vector<int> ans(100005);
vector<bool> seen(100005,false);

//colorは前の隣接辺の色

void bfs(int start){
    queue<P> Q;
    //secondはその頂点の前の隣接辺の色
    Q.push(make_pair(start,-1));
    while(!Q.empty()){
        P p = Q.front();Q.pop();
        int V = p.first;int C = p.second;
        seen.at(V) = true;
        int now = 1; //←一頂点ごとに見ていくのでとりあえず1で初期化
        for(P U : Edge.at(V)){
            int to = U.first;
            if(seen.at(to)) continue;
            seen.at(to) = true;
            if(C == now) now++; //同頂点・隣接辺の色と同じ場合は1色足す
            ans.at(U.second) = now;
            Q.push(make_pair(to,now));
            now++;
        }
    }
}

int main() {
    int N;cin >> N;
    for(int i = 0;i<N-1;i++){
        int a,b;cin >> a >> b;
        a--;b--;
        Edge.at(a).push_back(make_pair(b,i));
        Edge.at(b).push_back(make_pair(a,i));
    }
    int MAXedge = 0;
    int s = 0;
    for(int i = 0;i<N;i++) {
        int e = Edge.at(i).size();
        connectedEdge.at(i) = e;
        if(MAXedge < e) s = i;
        MAXedge = max(MAXedge,e);
    }

    bfs(0);

    cout << MAXedge << endl;
    for(int i = 0;i<N-1;i++){
        cout << ans.at(i) << endl;
    }
}