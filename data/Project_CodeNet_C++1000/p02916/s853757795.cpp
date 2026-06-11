#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;

int main() {
    int N;cin>>N;
    vi A(N),B(N),C(N-1);
    for (int i = 0; i < N; i++){
        cin>>A[i]; A[i]--;
    }
    for (int i = 0; i < N; i++){
        cin>>B[i];
    }
    for (int i = 0; i < N-1; i++){
        cin>>C[i];
    }
    int ans=0;
    for (int i = 0; i < N; i++){
        ans+=B[i];
        if(i!=N-1 && A[i+1]==A[i]+1)ans+=C[A[i]];
    }
    cout<<ans<<endl;
}