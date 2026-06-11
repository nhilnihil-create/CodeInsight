#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<long long> e(N,0);
  int a; cin >> a;
  int maxlen=0;
  if(a>0){
    cout << 0 << endl;
    return 0;
  }
  e[a]++;
  for(int i=1; i<N; i++){
    cin >> a;
    e[a]++;
    maxlen=max(maxlen,a);
  }
  if(e[0]>1){
    cout << 0 << endl;
    return 0;
  }
  long long result=1;
  for(int i=1; i<=maxlen; i++){
    if(e[i]==0){
      cout << 0 << endl;
      return 0;
    }
    int c=e[i];
    while(c--){
      result*=e[i-1];
      result%=998244353;
    }
  }
  cout << result << endl;
}