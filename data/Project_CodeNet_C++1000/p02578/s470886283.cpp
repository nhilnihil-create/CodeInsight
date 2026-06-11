#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    vector<long long>A(N);
    for(long long i=0;i<N;i++){
        cin>>A[i];
    }
    long long ans=0,tmp=0;
    for(long long i=1;i<N;i++){
        if(A[i]<A[i-1]+tmp){
            ans+=A[i-1]+tmp-A[i];
            tmp=A[i-1]+tmp-A[i];
        }
        else{
            tmp=0;
        }
    }
    cout<<ans<<endl;
}
