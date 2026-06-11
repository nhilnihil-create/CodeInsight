#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

const ll X=1000000007;

int main() {
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,N){
    cin>>A.at(i);
  }
  vector<int> rbg(3,-1);
  ll ans=1;
  bool checked;
  rep(i,N){
    int count=0;
    checked=false;//i番目がもう足されたかどうか
    rep(j,3){
      if(rbg.at(j)==A.at(i)-1){
        count++;
        if(checked==false){
          rbg.at(j)++;
          checked=true;
        }
      }
    }
    ans*=count;
    ans%=X;
  }
  cout<<ans<<endl;
}

