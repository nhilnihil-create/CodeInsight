#include <iostream>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int c[20];
  for(int i=0;i<m;i++) cin >> c[i];

  int table[50001];
  table[0]=0;
  for(int i=1;i<=n;i++){
    int mi=table[i-1]+1;
    for(int j=0;j<m;j++){
      if(c[j]>i) continue;
      mi=min(mi,table[i-c[j]]+1);
    }

    table[i]=mi;
  }

  cout << table[n] << endl;

  return 0;
}