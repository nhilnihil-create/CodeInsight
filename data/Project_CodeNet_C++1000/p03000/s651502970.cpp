#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const ll INF = 1000000000;
const ll mod = 1000000007;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
bool seen[505][505];

//dpTable
//bool dp[100050];

int main(){
    int N,X;
    cin >> N >> X;
    vector<int> L(N);
    vector<int> D(N + 1);
    rep (i,N) {
        cin >> L.at(i);
        D.at(i + 1) = D.at(i) + L.at(i);
    }
    rep (i,N + 1) {
        if (D.at(i) > X) {
            cout << i << endl;
            break;
        }
        else if (i == N) {
            cout << N + 1 << endl;
            break;
        }
    }
    return 0;
}