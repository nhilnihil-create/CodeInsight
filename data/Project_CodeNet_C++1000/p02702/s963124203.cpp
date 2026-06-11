#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  string S; cin >> S;
  int N = S.size();
  int d[N];
  rep(i,N) d[i] = (int)(S[i]-'0');
  
  vector<int> powmod(N); //powmod[i]: 10^iを2019で割った余り
  powmod[0] = 1;
  rep(i,N){
    if (i==0) continue;
    powmod[i] = (powmod[i-1]*10)%2019;
  }

  vector<int> acum(N,0);
  vector<int> cnt(2019,0);
  cnt[0] = 1;
  for (int j=0;j<N;j++){
    if (j==0) acum[j] = d[N-1-j];
    else acum[j] = (acum[j-1] + d[N-1-j]*powmod[j])%2019;
    
    cnt[acum[j]]++;
  }

  int retval = 0;
  rep(i,2019) retval += cnt[i]*(cnt[i]-1)/2;
  cout << retval << endl;
  
  // cout << fixed << setprecision(6);
  return 0;
}
