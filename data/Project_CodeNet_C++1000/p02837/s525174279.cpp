#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {

    ll N;
    cin >> N;
    ll A[16];
    ll X[16][16];
    ll Y[16][16];

    for(int i=1;i<=N;i++){
        cin >> A[i];
        for(int j=1;j<=A[i];j++){
            cin >> X[i][j] >> Y[i][j];
        }
    }

    int ans = 0;
    for(int honest=0;honest<(1<<N);honest++){
        int ok = 1;
        for(int i=1;i<=N;i++){
            //cout << "honest=" << honest << endl;
            if(honest&(1<<(i-1))){
                //cout << "test=" << i << endl;
                for(int j=1;j<=A[i];j++){
                    int tmp = (honest>>(X[i][j]-1))&1 ;
                    //cout << "i=" << i << " j= " << j << endl;
                    //cout << "tmp=" << tmp << " y= " << Y[i][j] << endl;
                    if(tmp == Y[i][j]){
                    }
                    else{
                        ok = 0;
                    }
                }
            }
        }
        if(ok == 1){
            ans = max(ans,__builtin_popcount(honest));
        }
    }

    cout << ans << endl;
}