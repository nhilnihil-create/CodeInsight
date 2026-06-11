#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int v[n];
  rep(i,n)cin >> v[i];

  sort(v,v+n);
  double mix=v[0];
  rep(i,n-1){
    mix=(mix+v[i+1])/2;
  }
  cout << mix << endl;
}
