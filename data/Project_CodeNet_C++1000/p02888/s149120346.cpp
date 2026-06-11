#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
vector<int> l;

bool isOK(int a, int b, int c){
  return (l[a]<l[b]+l[c] && l[b]<l[c]+l[a] && l[c]< l[a]+l[b]);
}

int nibutan(int a, int b){
  int ok=b,ng=n,middle;
  while(ng - ok > 1){
    middle = (ok + ng) / 2;
    if(isOK(a,b,middle)) ok = middle;
    else ng = middle;
  }
  return ok-b;
}

int main(){
  cin>>n;
  l.resize(n);
  rep(i,n){
    cin>>l[i];
  }
  sort(l.begin(),l.end());
  int ans=0;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      ans+=nibutan(i,j);
    }
  }
  cout<<ans<<endl;
}
