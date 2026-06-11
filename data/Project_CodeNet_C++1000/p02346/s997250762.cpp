#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<(b);++i)
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

ll N,Q,c,x,y;
vector<int> bit;

void add(int i, int x){
    while(i <= N){
        bit[i] += x;
        i += i & -i;
    }
}

int sum(int x, int y){
    int res = 0;
    while(x > 0){
        res -= bit[x];
        x -= x & -x;
    }
    while(y > 0){
        res += bit[y];
        y -= y & -y;
    }
    return res;
}


int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    // init (1-indexed) //
    bit.resize(N+1,0);
    // init //

    REP(i,Q){
        cin >> c >> x >> y;
        if(c==0){
            add(x,y);
        } else {
            cout << sum(x-1,y) << endl;
        }
    }
    return 0;
}
