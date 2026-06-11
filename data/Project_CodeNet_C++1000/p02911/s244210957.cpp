#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int n,k,q;
  cin >> n>>k>>q;
  vector<int> a(q);
  rep(i,q){
    cin>>a.at(i);
    a.at(i)--;
  }
  vector<int>c(n,q);
  rep(i,q){
    c[a.at(i)]--;
  }
  rep(i,n) {
    if(c.at(i)<k){
      cout<<"Yes"<<endl;   
    }
    else{
      cout<<"No"<<endl;   
    }
  }
  cout<<endl;
}