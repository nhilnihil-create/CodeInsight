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
  int x = (int)(1.0*N/1.08);

  if ((int)(x*1.08)==N) cout << x << endl;
  else if ((int)((x+1)*1.08)==N) cout << x+1 << endl;
  else cout << ":(" << endl;

  return 0;
}
