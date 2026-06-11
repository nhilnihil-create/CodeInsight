#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,a,sum;
  cin>>N;
  sum=0;
  for(int i=0;i<N;i++){
    cin>>a;
    sum^=a;
  }
  if(sum==0){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
  return 0;
}
