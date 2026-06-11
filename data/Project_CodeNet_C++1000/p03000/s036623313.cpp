#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,x;
  cin >> n >> x;
  int l[n];
  rep(i,n){cin >> l[i];}
  
  int bound=1,num=0l;
  for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=0; j<=num; j++){
      sum += l[j];
    }
    if(sum<=x) bound++;
    num++;
  }
  cout << bound << endl;
}