#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int i,j,n,m,t[50001],c[21];
  cin >> n >> m;
  for(i = 0; i < m; i++) cin >> c[i];
  for(j = 0; j <= n; j++) t[j] = 10001;
  t[0] = 0;
  
  for(i = 0; i < m; i++){
    for(j = c[i]; j <= n; j++){
      t[j] = min( t[j], t[j-c[i]] + 1 );
    }
  }

  cout << t[n] << endl;;

  return 0;
}