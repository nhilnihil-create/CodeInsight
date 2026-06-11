#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N;
ll K;
ll A[200000], F[200000];

signed main(){
    cin >> N >> K;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> F[i];
    sort(A, A+N);
    reverse(A, A+N);
    sort(F, F+N);

    ll ok = 1'000'000'000'001;
    ll ng = -1;
    while(ok-ng > 1){
        ll m = (ok+ng)/2;
        ll k = 0;
        rep(i, N){
            if(A[i]*F[i] <= m) continue;
            k += A[i] - m/F[i];
        }
        if(k <= K) ok = m;
        else ng = m;
    }
    cout << ok << endl;
}