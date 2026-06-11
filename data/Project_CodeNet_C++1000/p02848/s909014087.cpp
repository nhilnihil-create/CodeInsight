#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  char S[10001];
  cin>>n>>S;
  int k=strlen(S);
  for(int i=0;i<k;i++){
      S[i]+=n;
      if(S[i]>'Z')S[i]-=26;
  }
  cout<<S<<endl;
}