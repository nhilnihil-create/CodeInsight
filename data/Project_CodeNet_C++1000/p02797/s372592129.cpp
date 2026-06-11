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
  int N, K, S; cin >> N >> K >> S;
  rep(i,K) cout << S << endl;
  if (S>2) rep(i,N-K) cout << S/2+1 << endl;
  else rep(i,N-K) cout << S+1 << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}

