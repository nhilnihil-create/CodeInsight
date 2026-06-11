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
    string n;
    cin >> n;
    int ans=0;
    int l = n.size();
    for(int i=1;i<l+1;++++i){
        double r = pow(10,i-1);
        // cout << r << endl;
        if(i==l){
            int h = stoi(n);
            ans+=(h-r+1);
        }
        else{
            ans+=(9*r);
            // cout << ans << endl;
        }
    }
    cout << ans;
    



    return 0;
}
