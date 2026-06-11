#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,j,n) for(int i = (j); i < (n); i++)
#define rep0(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    rep0(i,n)cin >> l[i];
    int ans = 0;
    rep0(i,n-2) rep(j,i+1,n-1) rep(k,j+1,n){
        int a,b,c;
        if(l[i] == l[j] || l[i] == l[k] || l[j] == l[k])continue;
        a = l[i] + l[j] - l[k];
        b = l[i] - l[j] + l[k];
        c = -l[i] + l[j] + l[k];
        if(a>0 && b>0 && c>0) ans++;
    }
    cout << ans << endl;
}