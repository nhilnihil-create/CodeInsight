#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>S;
  N=S.size();
  
  int count_a=0,count_b=0,count_c=0;
  for(int i=1; i<=(N-1)/2/2; i++){
    if(S.at(i-1)==S.at((N-1)/2+1-i-1)){
      count_a++;
    }
  }
  for(int i=1; i<=(N-(N+3)/2+1)/2; i++){
    if(S.at((N+3)/2+i-2)==S.at(N-i)){
      count_b++;
    }
  }
  for(int i=1; i<=N/2; i++){
    if(S.at(i-1)==S.at(N-i)){
      count_c++;
    }
  }
  if(count_a==(N-1)/2/2&&count_b==(N+1-(N+3)/2)/2&&count_c==N/2){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}