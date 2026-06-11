#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, N){
        cin >> A.at(i);
        if(A.at(i)==0){
            cout << 0 << endl;
            return 0;
        }
    }
    sort(A.rbegin(),A.rend());

    long long ans = 1;
    rep(i, N){
        if(A.at(i) > 1000000000000000000/ans){
            cout << -1 << endl;
            return 0;
        }else{
            ans *= A.at(i);
        }
    }
    cout << ans << endl;

    return 0;  
}