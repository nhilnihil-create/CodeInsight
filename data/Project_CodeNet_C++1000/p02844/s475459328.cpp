#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  string S;cin>>S;
  int cnt=0;
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=9;k++){
        int n=0;
        for(int d=0;d<S.size();d++){
          if(n==0&&S[d]-'0'==i)n++;
          else if(n==1&&S[d]-'0'==j)n++;
          else if(n==2&&S[d]-'0'==k){
            //cout<<i<<j<<k<<endl;
            n++;cnt++;break;
          }
        }
      }
    }
  }
  cout<<cnt<<endl;
}