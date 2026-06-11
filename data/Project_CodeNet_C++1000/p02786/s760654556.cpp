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
    unsigned long long h;
    cin >> h;
    unsigned long long a = 1;
    unsigned long long ans=0;
    while(h){
        ans  += a;
        if(h%2==0){
            h = h/2;
        }
        else{
            h = (h-1)/2;
        }
        a*=2;
        if(h==1){
            ans += a;
            h=0;
        }
    }
    cout << ans;

    return 0;
}