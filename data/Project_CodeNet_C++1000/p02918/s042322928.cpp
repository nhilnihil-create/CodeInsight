#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N,K;
  cin>>N>>K;
  vector<char> S(N);
  int cntp = 0,cntn = 0;
  for(int i = 0; i < N; i++) {
    cin >> S[i];
    if(i >0){
      if(S[i-1]=='R' && S[i]=='L') {
        cntp++;
      }
      if(S[i-1]=='L' && S[i]=='R') {
        cntn++;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <N; i++) {
    if(N==1){ 
      ans=0;
      break;
    }
    else {
      if(i==0){
        if(S[i]=='R'&&S[i+1]=='R')ans++;
      }
      else if(i==N-1){
        if(S[i]=='L'&&S[i-1]=='L')ans++;
      }
      else{
        if((S[i]=='R'&&S[i+1]=='R')||(S[i]=='L'&&S[i-1]=='L'))ans++;
      }
    }
  }
  if(2*K>=cntn+cntp) {
    ans=N-1;
  }
  else{
    ans+=2*K;
  }
  cout<<ans<<endl;
}