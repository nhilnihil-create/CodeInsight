#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> A(n);
    for(int i=0; i<n; ++i) cin>>A[i];
    long long current=1000;

    for(int i=1; i<n; ++i){

        long long stocks=0;

        if(A[i-1]<A[i]) stocks = current/A[i-1];
        current += (A[i]-A[i-1])*stocks;
        //cout<<current<<"\n";
    }
    cout<<current<<"\n";
}