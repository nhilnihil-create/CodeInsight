#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,M,X,i,k,sum,m;
  ll min = 1111111111;
  ll C[22];
  ll A[22][22];
  bool a = false;
  cin >> N >> M >> X;
  for(i=0;i<=N-1;i++){
    cin >> C[i];
    for(k=0;k<=M-1;k++)
      cin >> A[i][k];
      }
  for(int bit = 0;bit < (1<<N);bit++){
    bool x = true;
    sum = 0;
    for(k=0;k<=M-1;k++){
      m = 0;
      for(i=0;i<=N-1;i++){
        if (bit & (1 << i)) m += A[i][k];
      }
      if(m<X) x = false;
    }
    for(i=0;i<=N-1;i++)
      if(bit & (1 << i)) sum += C[i];
    if(x && sum < min) min = sum,a=true;  
  }
  if(a) cout << min << endl;
  else cout << -1;
}