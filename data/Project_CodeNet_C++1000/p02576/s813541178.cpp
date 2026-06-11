#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n,x,t;
    int ans = 0;
    cin>>n>>x>>t;
    while(n > 0){
        ans++;
        n -= x;
    }
    cout<<ans*t<<endl;
    return 0;
}