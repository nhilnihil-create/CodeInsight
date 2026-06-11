#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main() {
    int n; cin>>n;
    vec a(n+2);
    vec b(n+1);
    rep(i,n+1){
        cin>>a[i];
    }

    a[n+1] = 0;

    rep(i,n){
        cin>>b[i];
    }

    b[n] = 0;

    ll sum=0;
    for(int i=0; i<=n; i++){
        int mn;
        mn=min(a[i],b[i]);
        a[i]-=mn; b[i] -= mn;
        int mnn;
        mnn=min(a[i+1],b[i]);
        a[i+1]-=mnn;
        sum+=mn+mnn;
    }
    
    cout<<sum<<endl;
    
}