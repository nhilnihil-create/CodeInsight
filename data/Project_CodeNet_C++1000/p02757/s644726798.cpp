#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,N,P;
  cin >> N >> P;
  vector<int> S(N);
  for(i=0; i<N; i++){
    scanf("%1d",&S[i]);
  }
  long long ans=0;
  if(P == 2 || P == 5){
    for(i=0; i<N; i++){
      if(S[i]%P == 0) ans += i+1;
    }
    cout << ans;
  }
  else{
    vector<long long> ret(P,0);
    vector<int> digit_ret(N);
    long long tmp=1;
    for(i=0; i<N; i++){
      digit_ret[i] = tmp;
      tmp = (tmp*10)%P;
    }
    tmp = 0;
    for(i=N-1; i>=0; i--){
      tmp = (tmp + S[i]*digit_ret[N-i-1])%P;
      ret[tmp]++;
    }
    for(i=0; i<P; i++){
      tmp = ret[i];
      ans += tmp*(tmp-1)/2;
    }
    cout << ans+ret[0];
  }
  return 0;
}