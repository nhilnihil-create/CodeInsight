#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=100000007;
const ll INF=1000000101001;
int main(){
 int n,k;cin>>n>>k;
 int h[n];
 int cnt=0;
 rep(i,n){
     cin>>h[i];
     if(h[i]>=k)cnt++;
 }
 cout << cnt << endl;
}