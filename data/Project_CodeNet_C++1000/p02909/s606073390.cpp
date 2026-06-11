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
 string s;cin >> s;
 string t[3]={"Sunny","Cloudy","Rainy"};
 rep(i,3){
     if(s==t[i])cout << t[(i+1)%3] << endl;
 }
}