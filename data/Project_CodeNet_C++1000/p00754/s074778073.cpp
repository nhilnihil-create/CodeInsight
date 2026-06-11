#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define RFOR(i,m,n) for(int i=m;i>=n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265


bool f(string s){
  vector<char> q;

  rep(i,s.size()){
    if(s[i]=='('||s[i]=='[') q.push_back(s[i]);
    if(s[i]==')'){
      if(q.size()==0) return false;
      if(q[q.size()-1]=='[') return false;
      q.pop_back();
    }
    if(s[i]==']'){
      if(q.size()==0) return false;
      if(q[q.size()-1]=='(') return false;
      q.pop_back();
    }
  }

  if(q.size()) return false;

  return true;
}



int main(){

  while(1){
    string s;
    char c;
    c = getchar();
    while(c!='\n'){
      s+=c;
      c = getchar();
    }
    if(s.size()==1&&s[0]=='.') break;
    if(f(s))
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }


  return 0;
}


