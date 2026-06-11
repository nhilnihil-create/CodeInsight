#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include <cmath>
//#include <bits/stdc++.h>
using namespace std;

// long int f(vector<long int> a,vector<long int> b,vector<long int> c,vector<long int> d,int N, int M){
     
 //}

long int ans=0;
int N,M,Q;
vector<int> A;
vector<long int> a,b,c,d;

void f(int n){
    if (n==N){
        long int x=0;
        for (int i=0;i<Q;i++){
            if(A[b[i]-1]-A[a[i]-1]==c[i]) x+=d[i];
        }
        ans=max(ans,x);
        return;
    }
    else{
        for (int i=(n==0?1:A[n-1]);i<=M;i++){
            A.push_back(i);
            f(n+1);
            A.pop_back();
        }
        return;
    }
}

int main(){
    cin>>N>>M>>Q;
    long int x;
    for (int i=0;i<Q;i++){
        cin>>x;a.push_back(x);
        cin>>x;b.push_back(x);
        cin>>x;c.push_back(x);
        cin>>x;d.push_back(x);
    }
    f(0);
    cout<<ans<<endl;
    return 0;
}