#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  

int main(void){
  long res=0;
  long i,j,k;
  long x,y;
  long n,d;
  
  cin>>n>>d;
  for(i=0;i<n;i++){
    cin>>x>>y;
    if(x*x+y*y<=d*d){
      res++;
    }
  }

  cout<<res<<endl;
  return 0;
}