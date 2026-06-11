#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;

int main(){
    long int N,K,S;   
    cin>>N>>K>>S;
    rep (i,K)  cout<<S<<" ";
    for (int i=K;i<N;i++){
        if (S>10000) cout<<S-1<<" ";
        else cout<<S+1<<" ";
    }
    cout<<endl;
    return 0;
}