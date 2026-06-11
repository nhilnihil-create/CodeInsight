#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int n,m;
vector<int> a;

bool isOK(int index, int x){
  if(a[index] <= x) return 1;
  else return 0;
}

int binarysearch(int x){
  int ok = -1, ng=n-1;
  while(ng-ok>1){
    int middle=(ok+ng)/2;
    if(isOK(middle,x)) ok=middle;
    else ng=middle;
  }
  return ok+1;
}

int main(){
  cin>>n>>m;
  a.resize(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  rep(i,m){
    a[n-1]/=2;
    if(n==1) continue;
    int x =a[n-1];
    a.pop_back();
    int index = binarysearch(x);
    a.insert(a.begin()+index,x);
  }
  ll ans=0;
  rep(i,n){
    ans+=a[i];
  }
  cout<<ans<<endl;
}

