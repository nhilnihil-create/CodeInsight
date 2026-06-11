#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
  ll N,P;
  string S;
  cin >> N >> P >> S;

  if(P==2 || P==5){
    ll answer=0;
    rep(i,N){
      if((S[i]-'0')%P == 0){
        answer+=i+1;
      }
    }
    cout << answer << endl;
    return 0;
  }

  vector<int> d(N+1);
  ll count=1;
  for(int i=N-1; 0<=i; i--){
    int a = (S[i]-'0') * count % P ;
    d[i]=(d[i+1]+a)%P;
    count*=10;
    count%=P;
  }

  vector<int> sum(P);
  ll answer=0;
  for(int i=N; 0<=i; i--){
    answer+=sum[d[i]];
    sum[d[i]]++;
  }

  cout << answer << endl;
  
 
}