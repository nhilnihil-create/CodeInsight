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
    int n,m;
    cin >> n >> m;
    vector<int> w(n,-1);
    bool flag = false;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        if(w[a-1]==-1){
            w[a-1] = b;
        }
        else{
            if(w[a-1]!=b){
                flag=true;
            }
        }
    }
    if(n==1){
        if(w[0]==0){
            cout << 0;
            return 0;
        }
    }
    if(m==0&&n==1){
        cout << 0;
        return 0;
    }
    rep(i,n){
        if(w[i]==-1){
            if(i==0){
                w[i]=1;
            }
            else{
                w[i] = 0;
            }
        }
    }
    if(flag){
        cout << -1;
        return 0;
    }
    if(w[0]==0){
        cout << -1;
        return 0;
    }
    else{
        rep(i,n){
            cout << w[i];
        }
    }

    return 0;
}