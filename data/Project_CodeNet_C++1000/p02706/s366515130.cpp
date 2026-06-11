#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
  int n,m;
  cin >> n>>m;
  int a[m];
  REP(i, m) {
    cin>>a[i];
  }
  // sort(a,a+m);
  int sum = 0;

  REP(i, m){
    sum +=a[i];
    }

    if( n-sum >=0){
      cout<<n-sum<<"\n";
    }
    else{
      cout<<"-1\n";
    }


  
  return 0;
}
