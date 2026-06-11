#include <bits/stdc++.h>
using namespace std;
 int main() {
 int N;
 cin>>N;
 vector<long long> test(N);
  bool zero=false;
 
  for(int i=0;i<N;i++){
  cin>>test.at(i);
    if(test.at(i)==0){
    zero=true;
    }
  }
  if(zero){
  cout<<0<<endl;
  }else{
   long long sum=1;
   bool dekakunai=true;
   for(int i=0;i<N;i++){
    
   if(test.at(i)<=1000000000000000000/sum){
   sum=sum*test.at(i);
   }else{
     dekakunai=false;
     cout<<-1<<endl;
     
     break;
     }
    }
    if(dekakunai){
      cout<<sum<<endl;
    }
 }

}