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
  int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  A--, B--, C--, D--;
  string S; cin >> S;
  bool possible1 = true, possible2 = false;
  for (int i=A+1;i<max(C,D)-1;i++){
    if (i+1<N && S[i]=='#' && S[i+1]=='#') possible1 = false;
  }
  for (int i=B-1;i<=D-1;i++){
    if (S.substr(i,3)=="...") possible2 = true;
  }

  if (C<D && possible1) cout << "Yes" << endl;
  else if (possible1 && possible2) cout << "Yes" << endl;
  else cout << "No" << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}

