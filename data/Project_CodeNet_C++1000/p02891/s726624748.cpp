#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  string S;
  int64_t K;
  cin>>S>>K;
  int N=S.size();
  auto ans= [&](string T){
    int64_t cnt=1,ans=0;
    int n=T.size();
    for(int i=0;i<n;i++){
      if(T[i]==T[i+1]){cnt++;}
      if(i==n-1){ans+=cnt/2;}
      else if(cnt>=2&&T[i]!=T[i+1]){ans+=cnt/2;cnt=1;}
    }
    return ans;
  };

  set<char>k;
  for(int i=0;i<N;i++){
    k.insert(S[i]);
  }
  if(k.size()==1){cout<<N*K/2<<endl;}
  else if(S[0]!=S[N-1]){cout<<ans(S)*K<<endl;}
  else{
    int r=0,l=0;
    for(int i=0;i<N;i++){
      if(S[i]==S[0]){r++;}
      else{break;}
    }
    for(int i=N-1;i>=0;i--){
      if(S[i]==S[N-1]){l++;}
      else{break;}
    }//cout<<ans(S)<<ans(S+S)<<endl;
    int d=ans(S+S)-ans(S);
    cout<<ans(S)+(K-1)*d<<endl;
    //cout<<ans(S)*K-(r/2+l/2-(r+l)/2)*(K-1)<<endl;
  }
  return 0;
}