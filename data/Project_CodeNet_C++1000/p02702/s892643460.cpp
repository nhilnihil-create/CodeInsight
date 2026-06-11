#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#define rep_zero(i, n) for(int i=0; i<n; i++)
#define rep(i, n) for(int i=1; i<n; i++)
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    int l = s.length();
    int t[l+1], u[l];
    rep_zero(i, l){
        u[i] = int(s[l-i-1]-'0');
        //cout <<" " << u[i];
    }
    //　cout << endl;
    t[0] = 0;
    int x = 1;
    rep_zero(i, l){
        t[i+1] = t[i]+u[i]*x;
        t[i+1] %= 2019;
        x = x*10%2019;
    }
    rep_zero(i, l+1){
        // cout << "i="<<i<<", t[i]="<<t[i] << endl;
    }
    ll ans = 0;
    vector<int> count(2019,0);
    rep_zero(i, l+1){
        // cout << "i="<<i<<", t[i]="<<t[i] << endl;
        ans += count[t[i]];
        count[t[i]] += 1;
    }
    cout << ans << endl;
}