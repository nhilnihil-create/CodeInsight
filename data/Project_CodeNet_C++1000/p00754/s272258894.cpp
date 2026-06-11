#include<iostream>
#include<cstdio>
#include<deque>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

bool check(string &s,int sp,int ep) {
  int a = 0, b = 0;
  REP(i,sp+1,ep) {
    if( s[i] == '(' ) ++a;
    if( s[i] == '[' ) ++b;
    if( s[i] == ')' ) --a;
    if( s[i] == ']' ) --b;
    if( a < 0 || b < 0 ) return false;
  }
  return a == 0 && b == 0;
}

int main() {
  string s;
  while( getline(cin,s), s != "." ) {
    bool ok = true;
    deque<int> a,b;
    rep(i,(int)s.size()) {
      if( s[i] == '(' ) a.push_back(i);
      if( s[i] == '[' ) b.push_back(i);
      if( s[i] == ')' ) {
	if( a.empty() ) { ok = false; break; }
	int sp = a.back(); a.pop_back();
	if( !check(s,sp,i) ) { ok = false; break; }
      }
      if( s[i] == ']' ) {
	if( b.empty() ) { ok = false; break; }
	int sp = b.back(); b.pop_back();
	if( !check(s,sp,i) ) { ok = false; break; }
      }
    }
    if( a.size() || b.size() ) ok = false;
    puts(ok?"yes":"no");
  }
  return 0;
}