#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 300000
int p[N];
int main(){
  int n;
  for(int i=0;i<N;++i) p[i]=1;
  p[0]=p[1]=0;
  for(int i=2;i<N;++i)
    if(p[i])
      for(int j=2;i*j<N;++j)
	p[i*j]=0;
  while(cin>>n,n){
    int cnt = 0;
    for(int i=n+1;i<=n*2;++i) cnt+=p[i];
    cout << cnt << endl;
  }
  return 0;
}