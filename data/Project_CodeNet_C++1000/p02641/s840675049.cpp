#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N, X;
    cin >> X >> N;
    vector<int> p(N);
    rep(i, N) cin >> p.at(i);
    int ans;
    long long min_dis = INF;
    for(int i=0;i<=101;i++){
        bool check = false;
        rep(j, N){
            if(p.at(j) == i) check = true;
        }
        if(check) continue;
        if(abs(i-X)<min_dis){
            ans = i;
            min_dis = abs(i-X);
        }
    }
    cout << ans << endl;
    return 0;    
}