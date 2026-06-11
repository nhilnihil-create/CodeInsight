#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll=long long;
using P=pair<int,int>;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define el '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

vector<vector<int>> card(3, vector<int>(3));
int n;

void mark(int x){
    rep(i, 0, 3) rep(j, 0, 3) if(card[i][j] == x) card[i][j] = INF;
}

int main(){
    rep(i, 0, 3) rep(j, 0, 3) cin >> card[i][j];
    cin >> n;
    rep(_, 0, n){
        int t; cin >> t;
        mark(t);
    }

    rep(i, 0, 3){
        int suc = 0;
        rep(j, 0, 3) if(card[i][j] == INF) suc++;
        if(suc >= 3) {
            cout << "Yes" << el;
            return 0;
        }
    }

    rep(j, 0, 3){
        int suc = 0;
        rep(i, 0, 3) if(card[i][j] == INF) suc++;
        if(suc >= 3) {
            cout << "Yes" << el;
            return 0;
        }
    }

    if(card[0][0] == INF && card[1][1] == INF && card[2][2] == INF){
        cout << "Yes" << el;
        return 0;
    }
    if(card[0][2] == INF && card[1][1] == INF && card[2][0] == INF){
        cout << "Yes" << el;
        return 0;
    }

    cout << "No" << el;

    return 0;
}
