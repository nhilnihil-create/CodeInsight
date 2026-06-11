#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
#define PI 3.14159265358979323846264338327950L
typedef unsigned long long uint64;
using namespace std;
using ll = long long;
int main(){
  int a;
  cin >> a;
  string s,t;
  cin >> s >> t;
  rep(i,s.length()){
    cout << s[i] << t[i] ;
  }
  cout << endl;
  return 0;
}