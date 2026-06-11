#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int i=0;i<20;i++){
    if(N==(1<<i)){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  cout<<N+1<<" 2\n";
  for(int i=0;i<(N-1)/2;i++){
    cout<<i*2+2<<" "<<i*2+3<<"\n";
    cout<<i*2+3<<" 1\n";
    cout<<N+i*2+2<<" 1\n";
    cout<<N+i*2+2<<" "<<N+i*2+3<<"\n";
  }
  if((N&1)==0){
    int d2=log2(N);
    cout<<(1<<d2)+1<<" "<<N<<"\n";
    cout<<2*N-(1<<d2)<<" "<<N*2<<"\n";
  }
}
