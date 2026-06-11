#include<bits/stdc++.h>
using namespace std;

int main(){
long N;
  long sum=0;
  long max=0;
  cin>>N;
  vector <int>a(N); 
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
 
  for(int i=0;i<N;i++){
  if(a.at(i)>max){
  max=a.at(i);
  }
    else{
    sum+=max-a.at(i);
    }
  }
  cout<<sum<<endl;
  
}