#include <bits/stdc++.h>
using namespace std;

int n,m,p,sum;
int x[105];

int main(){
  int i;
  while(1){
    cin >> n >> m >> p;
    if(n+m+p==0)break;
    sum=0;
    for(i=1;i<=n;i++){
      cin >> x[i];
      sum+=x[i];
    }
    if(x[m]==0)cout << 0 << endl;
    else cout << sum*(100-p)/x[m] << endl;
  }
  return 0;
}

