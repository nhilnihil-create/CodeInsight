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

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> S(M), C(M);
    for(int i = 0; i < M; i++) cin >> S[i] >> C[i];
    for(int num = 0; num <= 1000; num++){
        string s = to_string(num);
        if(s.size() != N) continue;
        bool ok = true;
        for(int i = 0; i < M; i++){
            if(s[S[i] - 1] != '0' + C[i]) ok = false;
        }
        if(ok){
            cout << s << endl;
            return 0;
        }
    }
    puts("-1");
}
