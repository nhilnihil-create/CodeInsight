//#include <math.h>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#include<stdio.h>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    int n,r;
    cin >> n>>r;
    int ans=0;
    rep(i,100000000){
        int m = pow(r,i);
        if(m==n){
            ans = i+1;
            break;
        }
        if(m>=n){
            ans = i;
            break;
        }
    }

    cout <<ans<<endl;
}



