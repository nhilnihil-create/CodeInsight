#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  vector<int> b(n);
  vector<int> ans;
  for(int i = n; i >= 1; i--){
    b[i-1]=b[i-1]%2;
    if(b[i-1]!=a[i-1]){
      ans.push_back(i);
      for(int j = 1; j*j <= i; j++){
        if(i%j==0){
          if(i!=1) b[j-1]++;
          if(i/j!=i && i/j!=j) b[i/j-1]++;
        }
      }
    }
  }
  cout<<ans.size()<<endl;
  for(auto x : ans){
    cout<<x<<" ";
  }
  cout<<endl;
}
