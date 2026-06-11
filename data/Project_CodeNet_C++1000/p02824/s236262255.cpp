#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

ll N, M, V, P;
VL A;

bool check(ll i){
    if(i < P) return true;
    if(A[i] + M < A[P-1]) return false;
    ll c = 0;
    c += (P - 1) * M;
    c += (N - i) * M;
    for(ll j = P-1; j < i; j++){
        c += min(M, max(A[i] + M - A[j], 0LL));
    } 
    if(c >= M * V) return true;
    else return false;
}

int main(){
    cin >> N >> M >> V >> P;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];

    sort(A.begin(), A.end(), greater<ll>());

    ll L = -1, R = N;
    while(R - L > 1){
        ll mid = L + (R-L)/2;
        if(check(mid)){
            L = mid;
        }else{
            R = mid;
        }
    }

    cout << L+1 << endl;
    return 0;
}