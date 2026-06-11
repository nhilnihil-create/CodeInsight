#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N,  Q;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N); 
    REP(i, 0, N){
        ll a;
        cin >> a;
        fw.add(i, a);
    }
    REP(i, 0, Q){
        ll q, a, b;
        cin >> q >> a >> b;
        if(q == 0){
            fw.add(a, b);
        }else{
            cout << fw.sum(a, b) << endl;
        }
    }
}