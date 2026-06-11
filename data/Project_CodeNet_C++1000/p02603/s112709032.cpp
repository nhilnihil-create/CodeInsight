#include <bits/stdc++.h>
using namespace std;
using ll=long long; 
int main(){
  long long N;
  ll money=1000;
  ll result;
  ll l=0;
  long long k=0;
  cin>>N;
  vector<long long> vec(N);
  for(long long i=0;i<N;i++){
    cin>>vec.at(i);
  }
  for(long long i=0;i<N-1;i++){
    
    if(vec.at(i)<vec.at(1+i)){
      
      k+=money/vec.at(i);
      l=money/vec.at(i);
      
      
      money-=l*vec.at(i);
     
      
      
    }
    if(vec.at(i)>vec.at(1+i)){
      money=money+k*vec.at(i);
      result=money;
      k=0;
      
    }
    
  }
  money+=vec.at(N-1)*k;
  if(money<result){
    cout<<result<<endl;
  }
  else{
    cout<<money<<endl;
  }
  
}
    
    
    
