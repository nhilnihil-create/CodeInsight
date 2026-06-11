#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int N,X;
  cin>>N>>X;
  int sum=0,cnt=1;
  int L[N];
  rep(i,N){
      cin>>L[i];
      sum+=L[i];
      
      if(sum>X){
          break;
      }
      cnt++;
  }
  cout<<cnt<<endl;
}