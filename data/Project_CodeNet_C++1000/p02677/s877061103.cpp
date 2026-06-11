#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<long int> sieve(long int n){
    long int arr[n+1];
    for(long int i = 0; i <= n;++i){
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    long int p= 2;
    while(p <= n){
        if(arr[p]){
            for(long int i = p*2; i <=n; i+=p){
                arr[i] = 0;
            }
        }
        p++;
    }
    vector<long int> ans;
    for(long int i = 2; i < n ; i++){
        if(arr[i]){
            ans.push_back(i);
        }
    }
    return ans;
    }
int main(){
    int a,b;
    double h, m, ang, dh, dm;
    cin>>a>>b>>h>>m;
    dh = h;
    dm = m;
    ang = abs((dm*6)-((dh*30)+(m/2)));
    ang = min(ang, 360-ang);
    cout<<fixed<<setprecision(20);
    cout<<sqrt(a*a+b*b-(2*a*b*cos(ang*(M_PI/180))))<<endl;
}