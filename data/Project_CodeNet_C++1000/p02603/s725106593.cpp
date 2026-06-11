#include<bits/stdc++.h>
using namespace std;
// greedy Solution
// int main(){
//     int n;
//     cin>>n;
//     vector<long long> A(n);
//     for(int i=0; i<n; ++i) cin>>A[i];
//     long long current=1000;

//     for(int i=1; i<n; ++i){

//         long long stocks=0;

//         if(A[i-1]<A[i]) stocks = current/A[i-1];
//         current += (A[i]-A[i-1])*stocks;
//         //cout<<current<<"\n";
//     }
//     cout<<current<<"\n";
// }

// Dp solution

int main(){
    int n;
    cin>>n;
    vector<long long> A(n);
    for(int i=0; i<n; ++i) cin>>A[i];
    vector<long long> Dp(n,0);
    Dp[0]=1000;
    for(int i=1; i<n; ++i){
        Dp[i] = Dp[i-1];
        for(int j=0; j<i; ++j){
            long long v = Dp[j]/A[j];
            long long w = Dp[j] + (A[i]-A[j])*v;
            Dp[i] = max(Dp[j],w);
        }
    }
    cout<<Dp[n-1]<<"\n";
}