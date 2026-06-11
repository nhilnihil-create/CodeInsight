#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const lli N = 10;
bool islunlun(string x){
    rep(i, x.size()-1){
        if(abs(x[i]-x[i+1]) > 1) return false;
    }
    return true;
}

lli k;

int main(void){
    cin >> k;
    queue<lli> q;
    rep(i, 9) q.push(i+1);
    lli ans;
    rep(i, k){
        lli x = q.front();
        if(i == k-1) ans = x;
        q.pop();
        if(x%10 != 0) q.push(10*x+x%10-1);
        q.push(10*x+x%10);
        if(x%10 != 9) q.push(10*x+x%10+1);
    }
    cout << ans << endl;
    return 0;
}
