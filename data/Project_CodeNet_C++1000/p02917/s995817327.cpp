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
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n-1) cin >> b[i];
    int ans = 0;
    rep(i,n){
        a[i] = b[i];
        if(i>0){
            a[i] = min(b[i-1], b[i]);
        }
    }
    a[n-1] = b[n-2];
    rep(i,n) ans += a[i];
    cout << ans << endl;
}