#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K,P;
  long long answer=-1000000007;
  cin>>N>>K;
  vector<int> NV(N);
  vector<int> C(N);
  for(int i=0;i<N;i++){
    cin>>P;
    NV.at(i)=P-1;
  }
  for(int i=0;i<N;i++){
    cin>>C.at(i);
  }
  for(int i=0;i<N;i++){
    int roop=0,v1=i;
    long long roopValue=0,answerI=0;
    vector<int> visited1(N,0);
    while(visited1.at(v1)==0){
      visited1.at(v1)=1;
      v1=NV.at(v1);
      roop++;
      roopValue+=C.at(v1);
    }
    if(roopValue>0){
      if(K/roop==0){
        answerI=C.at(NV.at(i));
        int v2=i,count=1;
        long long memo=0;
        while(count<=min(roop,K)){
          count++;
          v2=NV.at(v2);
          memo+=C.at(v2);
          answerI=max(answerI,memo);
        }
      }
      else{
        answerI=(K/roop-1)*roopValue;
        int remain=K%roop+roop,v2=i,count=1;
        long long memo=answerI;
        if(K/roop==1 && remain==roop){
          answerI+=C.at(NV.at(i));
        }
        while(count<=remain){
          count++;
          v2=NV.at(v2);
          memo+=C.at(v2);
          answerI=max(answerI,memo);
        }
      }
    }
    else if(roopValue<0){
      answerI=C.at(NV.at(i));
      int v2=i,count=1;
      long long memo=0;
      while(count<=min(roop,K)){
        count++;
        v2=NV.at(v2);
        memo+=C.at(v2);
        answerI=max(answerI,memo);
      }
    }
    answer=max(answer,answerI);
  }
  cout<<answer<<endl;
}
