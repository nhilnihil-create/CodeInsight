#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int counter(int x) {
    if(x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}
int main(){
    int N;
    cin >> N;
    vector<vector<pair<int,int>>> XY(N);
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        for(int j = 0; j < A; j++){
            int X, Y;
            cin >> X >> Y;
            XY[i].push_back(make_pair(X,Y));
        }
    }
    int max_n = 0;
    for(int bit = 0; bit < (1 << N); bit++){
        bool ok = true;
        for(int i = 0; i < N; i++){
            if(!(bit & (1 << i))) continue;
            for(auto p : XY[i]){
                if((bit >> (p.fi - 1) & 1) != bool(p.se)) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) max_n = max(counter(bit), max_n);
    }
    cout << max_n << endl;
}
