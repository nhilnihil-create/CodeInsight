#include <iostream>
using namespace std;
int main(){
  int N;
  cin>>N;
  int i;
  int people[N]={};
  for(i=0;i<=N-1;i++){
  cin>>people[i];
  }
  int average=0;
  for(i=0;i<=N-1;i++){
  average+=people[i];
  }
  average/=N;
  int average2=average+1;
  int answer=0;
  int answer2=0;
  for(i=0;i<=N-1;i++){
  answer+=(average-people[i])*(average-people[i]);
      answer2+=(average2-people[i])*(average2-people[i]);
  }
  if(answer<=answer2){
  cout<<answer;
  }
  else{
  cout<<answer2;
  }
}