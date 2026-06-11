#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
typedef long long ll;

int main() {
    ll K,N;
    cin >> K >> N;
    vector<ll> A(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll res=0;
    for(int i=0;i<N;i++){
        if(i==N-1)res=max(K-A[i]+A[0],res);
        else res=max(A[i+1]-A[i],res);
    }
    cout << K-res;
    return 0;
}
