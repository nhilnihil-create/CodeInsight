#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int N,K;
vector<int> A;


void imos(vector<int> &A){
    vector<int> tmp(N,0);
    rep(i,N){
        int left = max(0,i-A[i]);
        int right = min(N-1,i+A[i]);
        tmp[left]++;
        if(right+1<N)tmp[right+1]--;
    }
    rep(i,N-1)tmp[i+1] += tmp[i];
    A = tmp;
    return;
}

int main() {
    cin >> N >> K;
    A.resize(N);

    rep(i,N)cin >> A[i];
    
    K = min(K,50);
    rep(i,K)imos(A);

    rep(i,N)cout << A[i] << endl;

}