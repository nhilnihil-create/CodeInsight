#include<iostream>
#include<algorithm>

using namespace std;

int main(void){

  int n=123456*2+1;
  int p[n];
  
  fill(p,p+n,1);
  p[0]=p[1]=0;

  for(int i=2;i*i<n;i++)
    if(p[i]==1)
      for(int j=i*i;j<n;j+=i)
	p[j]=0;

  for(int i=1;i<n;i++)p[i]+=p[i-1];

  while(cin >> n, n){
    cout << p[n*2]-p[n] << endl;
  }
  
  return 0;
}