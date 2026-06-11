#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using pint = pair<int,int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

int main() {
    int n;
    cin>>n;
    vector<pint> ba(n);
    rep(i,n){
        int a,b;cin>>a>>b;
        ba[i] = {b,a};
    }

    sort(ba.begin(),ba.end());

    int now = 0;
    rep(i,n){
        now += ba[i].second;
        if (now > ba[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    return 0;
}