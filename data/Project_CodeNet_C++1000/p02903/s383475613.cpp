#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

int s[1010][1010];

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    rep(i, b){
        rep(j, a){
            s[i][j] = 1;
        }
    }
    for(int i = b; i < h; i++){
        for(int j = a; j < w; j++){
            s[i][j] = 1;
        }
    }
    rep(i, h){
        rep(j, w){
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}