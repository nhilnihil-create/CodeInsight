#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;


int main(){
    int N; cin >> N;
    vector<int> P(N), Q(N);
    rep(i,N) cin >> P[i];
    rep(i,N) cin >> Q[i];

    vector<int> T(N);
    for(int i = 1; i <= N; i++){
        T[i-1] = i;
    }

    int a, b;
    a = b = 0;
    int index = 0;
    do{
        bool isA = true;
        bool isB = true;
        rep(i,N){
            if (P[i] != T[i]){
                isA = false;
            }
            if (Q[i] != T[i]){
                isB = false;
            }
        }
        if (isA) a = index;
        if (isB) b = index;

        index++;
    } while(next_permutation(T.begin(),T.end()));
    
    cout << abs(a-b) << endl;
   
} 