#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    ll pseq = -1;
    rep(i, N) {
        if(A[i] >= 0) {pseq = i;
        break;}
    }
    //cout << pseq << endl;
    vector<P> res;
    if(pseq > 0) {
        for(ll i=pseq; i<N-1; i++) {
            res.push_back(P(A[0], A[i]));
            A[0] -= A[i];   
        }
        for(ll i=0; i<pseq; i++) {
            res.push_back(P(A[N-1], A[i]));
            A[N-1] -= A[i];
        }
      
    } else if(pseq == 0) {
        for(ll i=pseq+1; i<N-1; i++) {
            res.push_back(P(A[0], A[i]));
            A[0] -= A[i];   
        }
        res.push_back(P(A[N-1], A[0]));
        A[N-1] -= A[0];
       
    } else {
        for(ll i=0; i<N-1; i++) {
            res.push_back(P(A[N-1], A[i]));
            A[N-1] -= A[i];
        }    
    }
    
    
     cout << A[N-1] << endl;
    for(auto& p: res) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
    
}