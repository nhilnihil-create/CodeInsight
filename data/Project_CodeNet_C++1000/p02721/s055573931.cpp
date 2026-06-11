#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include <cmath>
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;
//void narabekae(string s[]){
    
//}


int main(){
    int N,K,C;
    cin>>N>>K>>C;
    string S;
    cin>>S;
    //for (int i=0;i<N;i++) cin>>S[i];
    vector<int> v;
    int j=0,k=0;
    while(k<K&&j<N){
        if (S[j]=='o'){
            //cout<<j<<" ";
            v.push_back(j);
            j+=C+1;
            k+=1;
        }
        else j+=1;
    }
    vector<int> w;
    j=N-1;
    k=0;
    while(k<K&&j>=0){
        if (S[j]=='o'){
            //cout<<j<<" ";
            w.push_back(j);
            j-=C+1;
            k+=1;
        }
        else j-=1;
    }
    rep(i,K){
        if (v[i]==w[K-1-i]) cout<<v[i]+1<<endl;
    }
    return 0;
}