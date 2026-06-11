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
    int x,y;
    cin>>x>>y;
    if (y%2==1){
        cout<<"No"<<endl;
        return 0;
    }
    
    if(y<x*2){
        cout<<"No"<<endl;
        return 0;
    }
    
    if(y>x*4){
        cout<<"No"<<endl;
        return 0;
    }
    
    cout<<"Yes"<<endl;
}