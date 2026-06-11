#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int kk=s.length();
  int t=(kk-1)/2;
  for(int i=0;i<t;i++){
    if(s[i]!=s[i+t+1]){printf("No\n");return 0;}
  }
  for(int i=0;i<t/2+1;i++){
    if(s[i]!=s[t-1-i]){printf("No\n");return 0;}
  }
  printf("Yes\n");
}
