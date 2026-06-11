#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;

struct Point{double x,y;};

void koch(int n,Point a,Point b){
  if(n==0) return;
  Point s,t,u;
  s.x=(2*a.x+b.x)/3;
  s.y=(2*a.y+b.y)/3;
  t.x=(a.x+2*b.x)/3;
  t.y=(a.y+2*b.y)/3;
  u.x=(t.x+s.x-sqrt(3)*t.y+sqrt(3)*s.y)/2;
  u.y=(sqrt(3)*t.x-sqrt(3)*s.x+t.y+s.y)/2;
  
  koch(n-1,a,s);
  cout<< fixed << setprecision(10) <<s.x<<" "<<s.y<<endl;
  koch(n-1,s,u);
  cout<< fixed << setprecision(10) <<u.x<<" "<<u.y<<endl;
  koch(n-1,u,t);
  cout<< fixed << setprecision(10) <<t.x<<" "<<t.y<<endl;
  koch(n-1,t,b);
}

int main(){
  int n;
  cin>>n;
  
  Point p1={0.0,0.0},p2={100.0,0.0};
  cout<< fixed << setprecision(10) <<p1.x<<" "<<p1.y<<endl;
  koch(n,p1,p2);
  cout<< fixed << setprecision(10) <<p2.x<<" "<<p2.y<<endl;
    
  return 0;
}

