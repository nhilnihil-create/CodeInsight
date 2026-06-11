#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
long long N,R,M=1e6,a,k,Inf=(1ULL<<62),p=Inf;

int main() {
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(begin(A),end(A));
    vector<bool> d(M+1);
    rep(i,N){
        a=A[i];
        if(p==a) { d[a]=1; continue; }
        p=a;
        for(k=2;a*k<=M;++k) d[a*k]=1;
    }
    rep(i,N) R+=!d[A[i]];
    cout << R;
}