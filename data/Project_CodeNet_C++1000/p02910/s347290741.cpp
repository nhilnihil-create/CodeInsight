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
string s;cin>>s;
bool ok=true;
int size=s.size();
rep(i,size){
    if(i%2==0&&s[i]=='L')ok=false;
    if(i%2!=0&&s[i]=='R')ok=false;
}
if(ok)cout << "Yes" << endl;
else cout << "No" << endl;
}