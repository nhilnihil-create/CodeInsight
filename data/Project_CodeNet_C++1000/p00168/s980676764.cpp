
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n) REP(i,0,n)

ll d[40];
void solve(){

}
void show(){
  for(int i=0;i<40;i++){
    cout<<i<<":"<<d[i]<<endl;
  }
}
void init(){
  fill(d,d+40,0);
  d[1]=1;
  d[2]=2;
  d[3]=4;
  for(int i=4;i<31;i++){
    d[i]=d[i-3]+d[i-2]+d[i-1];
  }
}
int main(){
  int n;
  init();
  while(cin >> n,n){
    cout<<(d[n]/3650)+1<<endl;
  }
  return 0;
}