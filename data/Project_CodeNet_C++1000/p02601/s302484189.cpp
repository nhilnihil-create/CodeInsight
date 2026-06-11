#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<queue>
#include<cstdio>
#define rep(i,n) for (int i=0;i<(n);++i)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    rep(i,k){
        if(a>=b){
            b = 2*b;
        }else if(b>=c){
            c = 2*c;
        }

        if(a<b&&b<c){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}