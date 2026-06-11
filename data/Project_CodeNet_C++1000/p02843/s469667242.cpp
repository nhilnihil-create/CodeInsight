#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;cin>>x;
    const int NM = 100000;
    bool dp[NM+200];
    rep(i, NM+200) dp[i] = false;
    for(int i=100;i<=105;i++) dp[i] = true;
    for(int i=100; i<=NM; i++) {
        if(dp[i]){
            for(int j=100; j<=105; j++){
                dp[i+j]=true;
            }
        }
    }
    cout<< (dp[x] ? 1:0) <<endl;
}