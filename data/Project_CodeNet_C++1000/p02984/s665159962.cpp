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
  int N; cin >> N;
  int A[N]; rep(i,N) cin >> A[i];
  ll x[N];

  int parity = 0;
  ll tot = 0;
  rep(i,N){
    tot += (1-2*parity)*A[i];
    (parity+=1) %= 2;
  } 
  x[0] = tot/2;
  for (int i=1;i<N;i++){
    x[i] = A[i-1] - x[i-1];
  }
  rep(i,N){
    if (i>0) cout << " ";
    cout << 2*x[i];
  }
  cout << endl;
  

  // cout << fixed << setprecision(10);
  
  return 0;
}
