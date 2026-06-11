#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

string s;

bool reach(int p, int g){
  for(int i=p; i<g; i++){
    if(s.at(i)=='#'&&s.at(i+1)=='#') return false;
  }
  return true;
}

bool over(int b, int c){
  if(s.at(b-1)=='.'&&s.at(b+1)=='.') return true;
  if(s.at(c-1)=='.'&&s.at(c+1)=='.') return true;
  
  for(int i=b; i<c-1; i++){
    if(s.at(i)=='.'&&s.at(i+1)=='.'&&s.at(i+2)=='.') return true;
  }
  return false;
}

int main(){
  int n,a,b,c,d;
  cin >>n>>a>>b>>c>>d;
  a--; b--; c--; d--;

  cin >> s;
  if(c<d){
    if(reach(a,c)&&reach(b,d)) cout<<"Yes";
    else cout<<"No";
  }else{
    if(reach(a,c)&&reach(b,d)&&over(b,d)) cout<<"Yes";
    else cout<<"No";
  }
}