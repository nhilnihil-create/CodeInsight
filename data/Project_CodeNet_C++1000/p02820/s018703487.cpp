#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main(){
    int N, K, R, S, P;
    cin >> N >> K >> S >> P >> R;
    string T;
    cin >> T;
    int res = 0;
    for(int i = 0; i < K; i++) {
        int flag = 0;
        for(int j = i; j < T.size(); j+=K) {
            if(flag) {
                if(T[j] == T[j-K]) {flag = 0; continue;}
            }
            flag = 1;
            if(T[j] == 'r') res += R;
            else if (T[j] == 's') res += S;
            else if(T[j] == 'p') res += P;
        }
    }
    cout << res << endl;
    return 0;
}

