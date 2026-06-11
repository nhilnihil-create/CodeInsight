#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  ll N,A,B,C,D;
  string S;
  cin>>N>>A>>B>>C>>D>>S;
  A--;
  B--;
  C--;
  D--;
  for(ll i=A;i+1<=C;i++){
    if(S[i]=='#'&&S[i+1]=='#'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  for(ll i=B;i+1<=D;i++){
    if(S[i]=='#'&&S[i+1]=='#'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  
  if(C<D){
    cout<<"Yes"<<endl;
    return 0;
  }

  for(ll i=B;i<=D;i++){
    if(S[i-1]=='.'&&S[i]=='.'&&S[i+1]=='.'){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
