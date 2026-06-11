#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = /*1'000'000'007LL;*/ 998'244'353LL;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

string S;
int A[500000];

signed main(){
    cin >> S;
    memset(A, -1, sizeof(A));

    if(S[0] == '<') A[0] = 0;
    if(S.back() == '>') A[S.size()] = 0;
    rep(i, S.size()-1){
        if(S[i] == '>' && S[i+1] == '<'){
            A[i+1] = 0;
        }
    }
    
    rep(i, S.size()-1){
        if(S[i] == '<' && S[i+1] == '<' && A[i] != -1){
            A[i+1] = A[i]+1;
        }
    }
    if(S.back() == '<') A[S.size()] = A[S.size()-1] + 1;
    
    for(int i=S.size()-1; i>0; i--){
        if(S[i-1] == '>' && S[i] == '>' && A[i+1] != -1){
            A[i] = A[i+1]+1;
        }
    }
    if(S[0] == '>') A[0] = A[1] + 1;

    rep(i, S.size()-1){
        if(S[i] == '<' && S[i+1] == '>'){
            A[i+1] = max(A[i], A[i+2]) + 1;
        }
    }

    //rep(i, S.size()+1) cout << A[i] << endl;

    ll ans = 0;
    rep(i, S.size()+1) ans += A[i];
    cout << ans << endl;
}