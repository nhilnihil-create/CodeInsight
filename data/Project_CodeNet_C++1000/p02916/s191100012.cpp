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
int n;cin>>n;
int a[n],b[n];
int c[n-1];
rep(i,n)cin >> a[i];
rep(i,n)cin>> b[i];
rep(i,n-1)cin >> c[i];
int sum=0;
rep(i,n){
    sum+=b[a[i]-1];
}
rep(i,n-1){
    if(a[i+1]==a[i]+1)sum+=c[a[i]-1];
}
cout << sum << endl;
}