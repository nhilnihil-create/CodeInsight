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
    int n;
    string s;
    cin >> n >>s;
    int cnt = 1;
    char pre = s[0];
    for(int i=1;i<n;i++){
        if(pre==s[i]) continue;
        else{
            pre = s[i];
            ++cnt;
        }
    }
    cout << cnt;

    return 0;
}