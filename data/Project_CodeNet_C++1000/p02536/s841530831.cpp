#include<bits/stdc++.h>
using namespace std;

vector<int>a[100005];
vector<bool>b(100005,false);

void c(int i){
  if(!b[i]){
    b[i]=true;
    for(auto v:a[i]){
      c(v);
    }
  }
}

void solve(){
  int n,m;
  int cnt=0;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int aa,bb;
    cin >> aa >> bb;
    aa--;
    bb--;
    a[aa].push_back(bb);
    a[bb].push_back(aa);
  }
  
  for(int i=0;i<n;i++){
    if(!b[i]){
      cnt++;
      c(i);
    }
  }
  cout << cnt-1 << endl;
}

int main(){
  solve();
}