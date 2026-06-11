#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
const ll inf = 1000000007;
int main() {
  double W,H,X,Y; cin  >>W>>H>>X>>Y;
  cout <<fixed<<setprecision(11)<<(W*H)/2<<" ";
  if(X==W/2&&Y==H/2)cout <<1<<endl;
  else cout <<0<<endl;
}