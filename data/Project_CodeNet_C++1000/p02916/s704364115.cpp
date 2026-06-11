#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int n;
    cin >> n;
    int a[n+1], b[n+1], c[n];
    rep1(i,n+1) cin >> a[i];
    rep1(i,n+1) cin >> b[i];
    rep1(i,n) cin >> c[i];
    int ans = 0;
    rep1(i,n+1){
        ans += b[a[i]];
        if(i >= 2 && a[i] == a[i-1] + 1){
            ans += c[a[i-1]];
        }
    }
    cout << ans << endl;
}