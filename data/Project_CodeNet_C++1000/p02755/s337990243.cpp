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
    int a,b;
    cin >> a >> b;
    for(int i=1;i<1001;i++){
        double q,w;
        q = i * 0.08;
        w = i * 0.10;
        if((int)q == a){
            if((int)w == b){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1 <<endl;
    return 0;
}