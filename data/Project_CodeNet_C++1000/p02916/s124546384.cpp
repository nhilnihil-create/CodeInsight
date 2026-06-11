#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
 
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> A(n),B(n),C(n);
    rep(i,n){
        cin>>A[i];
    }
    rep(i,n){
        cin>>B[i];
    }
    rep(i,n-1){
        cin>>C[i];
    }
    int sum = 0;
    rep(i,n){
        sum = sum + B[A[i]-1];
        if((A[i]-A[i-1])==1){
            sum = sum + C[A[i]-2];
        }
    }
    cout<<sum<<endl;
    return 0;
}