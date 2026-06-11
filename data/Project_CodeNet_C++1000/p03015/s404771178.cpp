#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int N=S.size();
  int64_t Q=1000000007;
  vector<int64_t> p(N);
  vector<int64_t> q(N);
  p[0]=2;
  q[0]=1;
  for(int i=1;i<N;i++){
    if(S[i]=='1'){
      p[i]=(p[i-1]*2)%Q;
      q[i]=(p[i-1]+q[i-1]*3)%Q;
    }
    else{
      p[i]=p[i-1];
      q[i]=(q[i-1]*3)%Q;
    }
  }
  cout<<(p[N-1]+q[N-1])%Q<<endl;
}

