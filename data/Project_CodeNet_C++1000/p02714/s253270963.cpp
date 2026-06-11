#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


//void warshall_floyd(int n){
//    for(int k=0;k<n;k++){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//            }
//        }
//    }
//}
//ll calc_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        ++res;
//        N /= 10;
//    }
//    return res;
//}
//ll sum_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        res += N % 10;
//        N /= 10;
//    }
//    return res;
//}

int main() {
    int N; string S;
    cin >> N >> S;
    long long r = 0, g = 0, b = 0;
    for (auto c : S) {
        if (c == 'R') ++r;
        else if (c == 'G') ++g;
        else ++b;
    }
    long long all = r * g * b;
    long long sub = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (S[i] == S[j]) continue;
            int k = j*2-i;
            if (k >= N || S[k] == S[i] || S[k] == S[j]) continue;
            ++sub;
        }
    }
    cout << all - sub << endl;
}


