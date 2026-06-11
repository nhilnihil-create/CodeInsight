#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

bool possible(vector<ll> &A, vector<ll> &F, ll K, ll N, ll X){
    rep(i,N){
        if (A[i] * F[N - 1 - i] > X){
            ll t = X / F[N - 1 - i];
            K -= (A[i] - t);
        }
    }
    if (K >= 0) return true;
    return false;
}

int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> A(N);
    vector<ll> F(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> F[i];
    }
    sort(all(A));
    sort(all(F));
    ll left = 0;
    ll right = 10000000000000;
    if (possible(A,F,K,N,0)) cout << 0 << endl;
    else{
        while(true){
            if (right - left == 1){
                cout << right << endl;
                break;
            }
            else{
                if (possible(A,F,K,N,(left + right) / 2)){
                    right = (left + right) / 2;
                }
                else{
                    left = (left + right) / 2;
                }
            }
        }
    }
}
