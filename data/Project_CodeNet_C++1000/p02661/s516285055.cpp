#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<60;

int main() {
    int N;
    cin>>N;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    sort(all(A));
    sort(all(B));
    if(N%2==0){
        ll mi=A[N/2-1]+A[N/2];
        ll ma=B[N/2-1]+B[N/2];
        cout<<ma-mi+1<<endl;
    }
    else{
        ll mi=A[N/2],ma=B[N/2];
        cout<<ma-mi+1<<endl;
    }
}