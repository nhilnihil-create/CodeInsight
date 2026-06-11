#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
  cin>>N>>K;
  if(((N-1)*(N-2))/2<K)
    cout<<-1<<endl;
  else{
  cout<<(N-1)+((N-1)*(N-2))/2-K<<endl;
    for(int i=2;i<=N;i++)
      cout<<1<<" "<<i<<endl;
    int a=(((N-1)*(N-2)))/2-K;
    int b=0;
    for(int k=3;k<=N;k++){
     if(b==a)
       break;
      else{
       for(int j=k-1;2<=j;j--){
       cout<<k<<" "<<j<<endl;
         b++; if(b==a)break;
       }
      }
    }
  }
   return 0;
}