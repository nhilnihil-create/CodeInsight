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
  int A, B, M; cin >> A >> B >> M;
  int a[A], b[B];
  int a_min=1000000, b_min=1000000; 
  rep(i,A) {
    cin >> a[i];
    a_min = min(a_min, a[i]);
  }

  rep(j,B) {
    cin >> b[j];
    b_min = min(b_min, b[j]);
  }


  int x, y, c, retval = a_min+b_min;
  rep(i,M){
    cin >> x >> y >> c;
    x--; y--;
    retval = min(retval, a[x]+b[y]-c);
  }

  cout << retval << endl;

  // cout << fixed << setprecision(6);
  return 0;
}
