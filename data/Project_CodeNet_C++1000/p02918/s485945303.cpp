#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K, i;
  cin>>N>>K;
  vector<char>S(N);
  for(i=0; i<N; i++)cin>>S[i];

  vector<char>is(N-1);
  for(i=0; i<N-1; i++){
    if(S[i]=='L' && S[i+1]=='R'){
      is[i] = 'b';
    }else if(S[i]=='R' && S[i+1]=='L'){
      is[i] = 'c';
    }else{//if(S[i]==S[i+1])
      is[i] = 'g';
    }
  }

  int bs, cs, gs;
  bs = cs = gs = 0;
  for(i=0; i<N-1; i++){
    switch(is[i]){
      case 'b': bs++;break;
      case 'c': cs++;break;
      case 'g': gs++;break;
    }
  }

  int ans = 0;
  int minbc = min(bs,cs);
  if(minbc >= K){
    ans = gs + K*2;
  }else{
    if(bs==cs){
      ans = gs + minbc*2;
    }else{
      ans = gs + minbc*2 + 1;
    }
  }

  if(gs==N-1)ans = gs;//整列していた時

  cout<<ans<<endl;
}