#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
 
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> B(n),C(n-1);
    rep(i,n-1){
        cin>>B[i];
    }
    int sum = 0;
    sum = sum + B[0];
    B[n-1] = 100000;
    rep(i,n-1){
        sum = sum + min(B[i],B[i+1]);
    }
    cout<<sum<<endl;
    
    return 0;
}