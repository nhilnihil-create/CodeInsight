#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans=0,c=0,temp=0,n=0;
  string S,T;
  cin >> S >> T;
  int s=S.size(),t=T.size();

  n = s-t+1;
  ans = t;
  int i,j;
  while(n){
    n--;
    i=c;
    c++;
    j=0;

    temp=0;
    for(i;i<s;i++){
      for(j;j<t;j++){
        if(S.at(i) == T.at(j)){
          break;
        }else{
          temp++;
          break;
        }
      }
      j++;
    }

    ans = min(ans,temp);
  }

  cout << ans << endl;
  return 0;
}