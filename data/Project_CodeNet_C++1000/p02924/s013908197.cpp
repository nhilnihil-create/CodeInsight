#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll f(ll n){
    return n*(n+1)/2;
}

int main(){
    ll n;cin >> n;
    cout << f(n-1) << endl;
}