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
  int N, K; cin >> N >> K;
  int maxK[N], tmp=0;
  int p[N];
  rep(i,N){
    cin >> p[i];
    if (i<K) tmp += p[i]+1;

    if (i==K-1) maxK[i] = tmp;
    else if (i>=K) maxK[i] = maxK[i-1] + p[i] - p[i-K];
  }

  int retval = 0;
  for (int i=K-1;i<N;i++) retval = max(maxK[i], retval);

  cout << fixed << setprecision(7);
  cout << retval/2.0 << endl;

  
  // cout << fixed << setprecision(10);
  
  return 0;
}

