#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef long long int ll;
 
template<class T> inline bool chmax(T& a,T b){ if(a<b){ a=b; return true;} return false; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){ a=b; return true;} return false; }
 
typedef pair<int,int> pair;

int main(){
  int a,b,c;
  cin >> a >> b >> c;

  bool x=(a==b && a!=c);
  bool y=(b==c && a!=c);
  bool z=(a==c && a!=b);
  if(x || y || z) puts("Yes");
  else puts("No");
}