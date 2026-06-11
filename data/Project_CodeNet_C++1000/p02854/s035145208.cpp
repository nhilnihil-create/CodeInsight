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
  ll A[N];
  ll R[N];
  rep(i,N) {
    cin >> A[i];

    if (i==0) R[i] = A[i];
    else R[i] = R[i-1] + A[i];
  }

  ll retval = 2020202020ll*200000ll+10;
  rep(i,N) retval = min(retval, abs(2*R[i]-R[N-1]));
  cout << retval << endl;


  // cout << fixed << setprecision(6);
  return 0;
}

