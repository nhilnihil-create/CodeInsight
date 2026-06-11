#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
ll gcd(ll a,ll b){
    if(b==0) return a;
    if(a==0) return b;
    if(a>=b){
        return gcd(b,a%b);
    }
    else{
        return gcd(a,b%a);
    }
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    cin >> a >> b;
    cout << a*b/gcd(a,b);

    return 0;
}