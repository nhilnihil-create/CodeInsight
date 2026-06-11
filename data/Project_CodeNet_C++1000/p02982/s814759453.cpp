#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#include<bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n, d; cin >> n >> d;
    int x[n][d];
    rep(i, n){
        rep(j, d){
            cin >> x[i][j];
        }
    }

    int ans=0;

    rep(i, n){
        reps(j, i+1, n){
            int dist = 0;
            rep(k, d){
                int diff = abs(x[i][k]-x[j][k]);
                dist += diff*diff;
            }

            int q,k = 1;
            while(dist>=k){
                if(dist==k*k){
                    ans++;
                }
                k++;
            }
        }
    }

    out(ans);
}