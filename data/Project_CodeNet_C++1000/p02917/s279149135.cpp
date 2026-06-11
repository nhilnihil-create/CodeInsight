#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;cin>>N;
    long long A[N],B[N-1];
    for(long long i=0;i<N-1;i++){
        cin>>B[i];
    }
    A[0]=B[0];
    for(long long i=1;i<N;i++){
        if(i==N-1){
            A[i]=B[i-1];    
        }
        else{
            A[i]=min(B[i],B[i-1]);
        }
    }
    long long ans=0;
    for(long long i=0;i<N;i++){
        ans+=A[i];
    }
    cout<<ans<<endl;
    return 0;
}