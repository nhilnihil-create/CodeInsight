#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;
ll N,K;
bool isOK(ll trial, vl &A, vl &F) {
    ll k=0;
    for (int i = 0; i < N; i++){
        k+=max(A[i]-trial/F[i],(ll)0);
        if(k>K)return false;
    }
    return true;
}

int main() {
    cin>>N>>K;
    vl A(N),F(N);
    for (int i = 0; i < N; i++){
        cin>>A[i];
    }
    for (int i = 0; i < N; i++){
        cin>>F[i];
    }
    sort(A.begin(),A.end());
    sort(F.begin(),F.end(),greater<ll>());
    ll ok = F[0]*A[N-1];
    ll ng = -1; 
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid,A,F)) ok = mid;
        else ng = mid;
    }
    cout<<ok<<endl;
}