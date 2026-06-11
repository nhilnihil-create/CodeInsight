#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#define ll long long
#define INF 100000000000
#define N 10000000
using namespace std;

int main(void){
    int x,n;
    cin>>x>>n;
    
    int data[n];
    for (int i=0; i<n; i++){
        cin>>data[i];
    }
    
    int p,q;
    p=x;
    q=x;
    
    while(true){
        bool a=true;
        for(int i=0; i<n; i++){
            if(data[i]==p) a=false;
        }
        
        if(a) break;
        
        p++;
    }
    
    while(true){
        bool a=true;
        for(int i=0; i<n; i++){
            if(data[i]==q) a=false;
        }
        
        if(a) break;
        
        q--;
    }
    
    if(x-q<=p-x) cout<<q<<endl;
    else cout<<p<<endl;
}