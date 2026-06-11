#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n) {
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  bool ex=false;
  rep(i,n){
    if(a[i]!=0){
      ex=true;
    }
  }
  if(!ex){
    cout<<"Yes"<<endl;
  }
  else{
    if(n%3!=0){
      cout<<"No"<<endl;
    }
    else{
      rep(i,3){
        rep(j,n/3){
          if(a[n/3*i+j]!=a[n/3*i]){
            ex=false;
          }
        }
      }
      if(ex){
        if((a[0]^a[n/3])!=a[n/3*2]){
          ex=false;
        }
      }
      if(ex){
        cout<<"Yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
    }
  }
}
