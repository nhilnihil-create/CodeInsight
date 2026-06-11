#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  string s1,s2,t1,t2,u1,u2;
  cin >> s1;
  s2 = s1;
  reverse(s1.begin(),s1.end());
  
  t1 = s2.substr(0,(s2.size()-1)/2);
  t2 = t1;
  reverse(t1.begin(),t1.end());
  
  u1 = s2.substr((s2.size()+3)/2 - 1);
  u2 = u1;
  reverse(u1.begin(),u1.end());

  if(s1 == s2 & t1 == t2 & u1 == u2)
    cout << "Yes" << endl;
  else cout << "No" << endl;
}