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
  int l[N+1], r[N+1];
  int cntl = 0, cntr = 0;
  rep(i,N+1){
    if (i<N){
      l[i] = cntl;
      if (S[i]=='<') cntl++;
      else cntl = 0;
    }
    else l[i] = cntl;
  }

  for (int i = N;i>=0;i--){
    if (i>0){
      r[i] = cntr;
      if (S[i-1]=='>') cntr++;
      else cntr = 0;
    }
    else r[i] = cntr;
  }

  ll retval = 0;
  rep(i,N+1) retval += max(l[i],r[i]);
  cout << retval << endl;



  // cout << fixed << setprecision(6);
  return 0;
}

