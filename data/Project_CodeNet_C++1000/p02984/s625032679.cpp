#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main() {
    int n; cin>>n;
    vll a(n+1);
    ll sum = 0;
    for(int i=1; i<=n; i++) {cin>>a[i]; sum += a[i];}

    vll x(n+1,0);

    ll sum_odd = 0;
    for(int i=1; i<=n; i+=2) sum_odd += a[i]*2;

    x[1] = sum_odd - sum;

    for(int i=2; i<=n; i++){
        x[i] = a[i-1]*2 - x[i-1];
    }

    for(int i =1; i<=n; i++){
        cout<<x[i]<<" ";
    }

}