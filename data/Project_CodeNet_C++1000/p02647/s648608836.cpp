#include<iostream>
#include<vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    vector<int>A(N);
    rep(i,N)cin>>A[i];
    rep(ki,K){
        vector<int>B(N+1);
        rep(i,N){
            int l=max(0,i-A[i]);
            int r=min(N,i+A[i]+1);
            B[l]++;
            B[r]--;
        }
        rep(i,N)B[i+1]+=B[i];
        B.pop_back();
        if(A==B)break;
        A=B;
    }
    
    rep(i,N)cout<<A[i]<<" ";
    return 0;
}