#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  string s;cin >> s;
  int n = s.size(),i,j,end[n] = {};
  for(i=0;i<n-1;i++){
    if(s[i] == 'R' && s[i+1] == 'L'){
      for(j=i;j>=0 && s[j]=='R';j--){
        end[i+((i-j)%2==1)]++;
      }
      for(j=i+1;j<n && s[j]=='L';j++){
        end[i+((j-i)%2==1)]++;
      }
    }
  }
  for(i=0;i<n;i++) printf("%d ",end[i]);
  printf("\n");
}