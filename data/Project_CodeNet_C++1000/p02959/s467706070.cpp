#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    long long A[N+1];
    for(long long i=0;i<N+1;i++){
        cin>>A[i];
    }
    long long B[N];
    for(long long i=0;i<N;i++){
        cin>>B[i];
    }
    long long ans=0;
    for(long long i=0;i<N;i++){
        ans+=min(A[i],B[i]);
        if(A[i]<B[i]){
            ans+=min(A[i+1],B[i]-A[i]);
            A[i+1]-=min(A[i+1],B[i]-A[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
