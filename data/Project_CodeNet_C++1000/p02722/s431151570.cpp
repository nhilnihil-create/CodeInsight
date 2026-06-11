#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin>>N;    
    long int i=2,ans=2;
    while (i*i<N-1){
        if ((N-1)%i==0) ans+=2;
        i+=1;
    }
    if (i*i==N-1) ans+=1;
    i=2;
    long long X=N;
    while(i*i<N){
        if (N%i==0){
            X=N;
        while(X%i==0){
            X=X/i;
        }
        if ((X-1)%i==0) ans+=1;
        }
        i+=1;
    }
    if (i*i==N) ans+=1;

    if (N!=2)cout<<ans<<endl;
    else cout<<1<<endl;
    return 0;
}