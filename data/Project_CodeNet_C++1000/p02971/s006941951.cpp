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
    cin >> n;
    vector<int> a(n);
    int m1=0,m2=0;
    rep(i,n){
        cin >> a[i];
        if(m1<=a[i]){
            m2=m1;
            m1=a[i];
        }
        else{
            if(m2<a[i]){
                m2=a[i];
            }
        }
    }
    rep(i,n){
        if(a[i]==m1){
            cout << m2<<endl;
        }
        else{
            cout << m1<<endl;
        }
    }

    return 0;
}