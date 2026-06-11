#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int N;
ll K;
vector<int> A, F;

/*
bool isOK(ll mid){
    ll count = 0;
    rep(i,N){
        count += max(0ll, A[i] - mid/F[i]);
    }
    if (count <= K) return true;
    else return false;
}
*/
ll binary_search(){
    ll ng = -1;
    ll ok = 1e12;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng) / 2;
        ll count = 0;
        rep(i,N){
            count += max(0ll, A[i] - mid/F[i]);
        }
        if(K >= count){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    return ok;
}

int main(){
    /*
    int N;
    ll K;
    */
    cin >> N >> K;
    
    //vector<int> A(N), F(N);
    A.assign(N,0), F.assign(N,0);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> F[i];

    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
    /*
    ll ng = -1;
    ll ok = 1e12;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng) / 2;
        ll count = 0;
        rep(i,N){
            count += max(0ll, A[i] - mid/F[i]);
        }
        if(K >= count){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    */
    ll ok = binary_search();
    cout << ok << endl;
}