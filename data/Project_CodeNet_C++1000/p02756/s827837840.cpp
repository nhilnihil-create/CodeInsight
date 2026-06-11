#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  int Q;
  cin>>S>>Q;
  vector<string> A(2,"");
  int f=0;
  for(int i=0;i<Q;i++){
    int T;
    cin>>T;
    if(T==1)
      f=1-f;
    else{
      int F;
      char C;
      cin>>F>>C;
      A[(f+F-1)%2]+=C;
    }
  }
  reverse(A[f].begin(),A[f].end());
  if(f==1)
    reverse(S.begin(),S.end());
  cout<<A[f]<<S<<A[1-f]<<endl;
}