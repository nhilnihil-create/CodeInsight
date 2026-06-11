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
    double w,h,x,y;
    cin >> w >> h >> x >> y;
    double ans = w * h /2;
    if(w == x * 2 && h == y * 2){
        cout << setprecision(10) <<  ans << " " << 1;
    }
    else{
        cout << setprecision(10) <<  ans << " " << 0;
    }

    return 0;
}