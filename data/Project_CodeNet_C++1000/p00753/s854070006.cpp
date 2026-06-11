#include<iostream>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
const int N = 300000;
int a[N];
int sum[N];
void generate(){
  rep(i,N)a[i]=i%2;
  for(int i=3;i*i < N;i+=2){
    if (a[i])
      for(int j=2*i;j<N;j+=i)a[j]=false;
  }
  a[1]=true;a[2]=true;
  int cnt=0;
  sum[0]=0;
  REP(i,1,N){
    sum[i]=sum[i-1];
    if (a[i])sum[i]++;
  }

}

main(){
  generate();
  int n;
  while(cin >>n && n){
    cout << sum[2*n]-sum[n] << endl;
  }
}