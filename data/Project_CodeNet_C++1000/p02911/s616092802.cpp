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
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,q;
    cin >> n >> k >>q;
    vector<int> a(n,k-q);
    rep(i,q){
        int m;
        cin >> m;
        a[m-1]+=1;
    }
    rep(i,n){
        if(a[i]<=0) cout << "No" << endl;
        else cout << "Yes" <<endl;
    }
    

    return 0;
}