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
    int n;cin >> n;
 string s,t;cin>>s>>t;
 string st=s+t;
 rep(i,2*n){
    if(i%2==0)st[i]=s[i/2];
    if(i%2!=0)st[i]=t[i/2];
 }
 cout << st << endl;
}