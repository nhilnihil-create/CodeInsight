#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vll = vector<long long>;
using vvll = vector<vll>;

int main(){
  ll N,A,B,C,D;
  cin>>N>>A>>B>>C>>D;
  string S;
  cin>>S;
  for(ll i=A+1;i<max(C,D);i++){
    if(S.at(i-2)=='#'&&S.at(i-1)=='#'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  if(C<D){
    cout<<"Yes"<<endl;
    return 0;
  }else{
    for(ll i=B;i<D+1;i++){
      if(S.at(i-2)=='.'&&S.at(i-1)=='.'&&S.at(i)=='.'){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
