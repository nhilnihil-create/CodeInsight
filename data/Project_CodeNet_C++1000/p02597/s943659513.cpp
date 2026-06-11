#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define N_MAX 200000
#define input(d) cin >> d;
#define inputs(n,d) for(int i=0;i<n;i++) {cin >> d[i];}
#define inputxy(n,x,y) for(int i=0;i<n;i++) {cin >> x[i] >> y[i];}
#define output(d) cout << d << endl;
#define outputs(n,d) for(int i=0;i<n;i++) {cout << d[i] << endl;}
#define outputxy(n,x,y) for(int i=0;i<n;i++) {cout << x[i] << y[i] << endl;}
#define f0(i,n) for(int i=0;i<n;i++)
#define f(i,a,b) for(int i=a;i<b;i++)
#define l long
#define ll long long
#define s string

int main(){
    ll n,d,x,y,ans=0;
    string st;
    input(n);
    input(st);

    f0(i,n){
        if(st[i] == 'R'){
            d++;
        }
    }
    f0(i,d){
        if(st[i] == 'W'){
            ans++;
        }
    }
    

    output(ans);
    return 0;
}