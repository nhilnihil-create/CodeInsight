#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L
#define MOD 1e9+7

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 

int main(){
    go(); 

    // code here
    string s;cin>>s;
    int n = s.length();
    int suf = 0;
    int pow_ten = 1;
    map<int,int> mp;
    forr(n-1,0,1){
        int value = s[i] - '0';
        suf = (suf + value*pow_ten)%2019;
        pow_ten = (pow_ten * 10)%2019;
        mp[suf]++;
    }
    long long ans = 0;
    for(auto node:mp){
        ans += (long long)node.second*(node.second-1)/2;
    }
    ans += mp[0];
    cout<<ans;
    
} 

