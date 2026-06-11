#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using ll=long long;

int main() {
    int N; cin>>N;
    vi A(N+1),B(N);
    ll sum=0;
    for (int i = 0; i < N+1; i++){
        cin>>A[i];
        sum+=A[i];
    }
    for (int i = 0; i < N; i++)cin>>B[i];
    ll ans=0;
    for (int i = 0; i < N; i++){
        int old_A=A[i],old_A2=A[i+1];
        A[i]=max(0,A[i]-B[i]);
        B[i]-=old_A-A[i];
        A[i+1]=max(0,A[i+1]-B[i]);
        B[i]-=old_A2-A[i+1];
    }
    ll sum2=0;
    for (int i = 0; i < N+1; i++)sum2+=A[i];
    cout<<sum-sum2<<endl;
}