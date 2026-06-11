#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  long A,B,M;cin >> A >> B >> M;

  long a[A],b[B],x[M],y[M],c[M];
  for(int i=0;i<A;i++){
      cin >> a[i];
  }

  for(int i=0;i<B;i++){
      cin >> b[i];
  }

  for(int i=0;i<M;i++){
      cin >> x[i] >> y[i] >> c[i];
  }


  int mina = 100000;
  for(int i=0;i<A;i++){
    if(mina > a[i]) mina = a[i];
  }

  int minb = 100000;
  for(int i=0;i<B;i++){
    if(minb > b[i]) minb = b[i];
  }

  int ans = mina+minb;
  int tmp;
  for(int i=0;i<M;i++){
      tmp = a[x[i]-1]+b[y[i]-1]-c[i];
      ans = min(ans,tmp);
  }

  cout << ans << endl;




}