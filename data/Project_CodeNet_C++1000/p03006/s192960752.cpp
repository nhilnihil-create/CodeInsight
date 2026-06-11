#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> x(N),y(N);
  for(int i=0;i<N;i++)  cin >> x.at(i) >> y.at(i);

  if(N==1){
    cout << 1 << endl;
    return 0;
  }

  int ans=1e9;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j)  continue;
      int count=0;
      int p=x.at(i)-x.at(j);
      int q=y.at(i)-y.at(j);
      for(int k=0;k<N;k++){
        for(int l=0;l<N;l++){
          if(k==l)  continue;
          int pt=x.at(k)-x.at(l);
          int qt=y.at(k)-y.at(l);
          if(pt==p && qt==q)  count++;
        }
      }
      ans=min(ans,N-count);
    }
  }
  cout << ans << endl;

  return 0;
}
