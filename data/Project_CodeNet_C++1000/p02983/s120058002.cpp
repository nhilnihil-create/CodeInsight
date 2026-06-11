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
  int retval = 2018;
  int L, R; cin >> L >> R;
  for (int i=L;i<=R;i++){
    for (int j=i+1;j<=R;j++){
      retval = min(retval, ((i%2019)*(j%2019))%2019);
      if (retval==0) break;
    }
    if (retval==0) break;
  }
  cout << retval << endl;
  
  // cout << fixed << setprecision(10);
  
  return 0;
}

