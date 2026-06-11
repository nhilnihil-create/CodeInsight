#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i =0;i<n;++i)

const int ma=3e6;
int ispr[ma];

int su[ma];

int main(){
  
  for(int i=2;i<ma;++i){
    if(ispr[i]) continue;
    su[i] = 1;
    for(int j=2*i;j<ma;j+=i)
      ispr[j] = 1;
  }
  
  rep(i,ma-1) su[i+1] += su[i];
  int n;
  
  while(cin >> n, n) cout << su[2*n] - su[n] << endl;
}