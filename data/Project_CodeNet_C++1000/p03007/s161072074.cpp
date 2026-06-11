#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> A(N),B;
    rep(i,N)cin >> A[i];
    sort(ALL(A));
    B = A;
    // A[0]に+を入れてマイナスしまくる
    for(int i=N-2;i>0;i--){
        if(A[i]>=0)A[0] -= A[i];
        else break;
    }
    for(int i=1;i<N;i++){
        if(A[i]<0) A[N-1] -= A[i];
        else break;
    }
    cout << A[N-1] - A[0] << endl;
    A = B;
    for(int i=N-2;i>0;i--){
        if(A[i]>=0){
            cout << A[0] << " " << A[i] << endl;
            A[0] -= A[i];
        }
        else break;
    }
    for(int i=1;i<N;i++){
        if(A[i]<0){
            cout << A[N-1] << " " << A[i] << endl;
            A[N-1] -= A[i];
        }
        else break;
    }
    cout << A[N-1] << " " << A[0]  << endl;
    
}