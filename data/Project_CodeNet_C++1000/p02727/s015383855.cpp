#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
typedef pair<int, int> PI;
const ll MOD = 1000000007;

int X, Y, A, B, C;
int p, q, r;
vector<PI> V;

int main(void){
    cin >> X >> Y >> A >> B >> C;
    REP(i, A){
        cin >> p;
        V.emplace_back(-p, 0);
    }
    REP(i, B){
        cin >> q;
        V.emplace_back(-q, 1);
    }
    REP(i, C){
        cin >> r;
        V.emplace_back(-r, 2);
    }
    sort(V.begin(), V.end());
    int a = 0, b = 0, count = 0;
    ll res = 0;
    for(int i = 0;i < X+Y;i++){
        PI t = V[count++];
        if(t.second == 0){
            if(a++ >= X){
                i--; continue;
            }
        }else if(t.second == 1){
            if(b++ >= Y){
                i--; continue;
            }
        }
        res += -t.first;
    }
    cout << res << endl;
    return 0;
}

