#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int N;
  cin>>N;
  int p[N];
  rep(i,N){
      cin>>p[i];
  }
  int cnt=0;
  for(int i=1;i<N-1;i++){
      if(p[i]-p[i-1]>0&&p[i]-p[i+1]<0){
          cnt++;
      }
      else if(p[i]-p[i-1]<0&&p[i]-p[i+1]>0){
          cnt++;
      }
  }
  cout<<cnt<<endl;
}