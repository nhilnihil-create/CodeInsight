#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

typedef struct{
  string n;
  int t;
  int e;
} process;

int main() {
  int n,q;
  cin >> n >> q;
  process p[n];
  queue<process> r;
  for(int i=0;i<n;++i){
    cin >> p[i].n >> p[i].t;
    r.push(p[i]);
  }

  process tmp;
  int ct=0;
  queue<process> f;
  while(!r.empty()){
    tmp = r.front();
    r.pop();
    if(tmp.t>q){
      tmp.t-=q;
      ct+=q;
      r.push(tmp);
    }
    else{
      ct+=tmp.t;
      tmp.e=ct;
      f.push(tmp);
    }
  }
  
  while(n-->0){
    tmp=f.front();
    cout << tmp.n << " " << tmp.e << endl;
    f.pop();
  }

}