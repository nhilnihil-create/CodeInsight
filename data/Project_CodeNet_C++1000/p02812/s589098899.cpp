#include <bits/stdc++.h>
using namespace std;


void solve(){
  int n,m,x,count=0;
  scanf("%d",&n);
  char s[50];
  scanf("%s",s);

  for(int i=0;i<n-2;i++){
    //printf("%c",s[i]);
    if(s[i]=='A'){
      if(s[i+1]=='B' && s[i+2]=='C')count++;
    }
  }



 printf("%d\n",count);
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}