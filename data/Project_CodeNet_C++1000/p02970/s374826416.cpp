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
    int n,d;
    cin >> n >> d;
    int a = 2*d+1;
    if(n%a==0){
        cout << n/a;
    }
    else{
        cout << n/a+1;
    }
    


    return 0;
}