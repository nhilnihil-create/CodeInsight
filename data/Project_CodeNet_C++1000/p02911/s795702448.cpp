#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    int a, b[n];
    rep(i,n) b[i] = k;
    rep(i,q){
        cin >> a;
        b[a-1]++;
    }
    rep(i,n){
        b[i] -=q;
        if(b[i] > 0) cout << "Yes" << endl;
        else  cout << "No" << endl;
    }
}