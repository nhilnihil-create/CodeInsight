#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int n, j;
    cin >> n;
    int d[n];
    rep(i,n) cin >> d[i];
    int ans = 0;
    rep(i,n){
        for(j=i+1; j<n; j++){
            ans += d[i]*d[j];
        }
    }
    cout << ans << endl;
}