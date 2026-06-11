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
    int h,n;
    cin >> h >> n;
    int sum=0;
    rep(i,n){
        int m;
        cin >> m;
        sum+=m;
    }
    if(sum>=h){
        cout <<"Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}