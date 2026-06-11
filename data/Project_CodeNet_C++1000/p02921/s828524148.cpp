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
string s,t;cin >> s >> t;
int cnt=0;
rep(i,3){
    if(s[i]==t[i])cnt++;
}
cout << cnt << endl;
}