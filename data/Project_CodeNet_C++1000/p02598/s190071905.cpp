#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N, K; cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A), greater<int>());
    int l = 0, r = A[0]; //左は絶対に無理、右は絶対に可能
    while(r - 1 > l){
        int middle = (l + r) / 2;
        int tmp = 0;
        rep(i, N){
            tmp += (A[i] + middle - 1) / middle - 1;
        }
        if(tmp <= K) r = middle;
        else l = middle;
    }
    cout << r << endl;
}