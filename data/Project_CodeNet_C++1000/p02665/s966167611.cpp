#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int64_t sum=0;
  int64_t line=0;
  int64_t amount;
  int64_t Ans=0;
  int flag=0;
  cin>>N;
  vector<int64_t> A(N+1);
  for(int i=0;i<N+1;i++){
    cin>>A.at(i);
    sum+=A.at(i);
  }
 
  vector<vector<int64_t>> value(N+1,vector<int64_t>(3,0));
    if(sum==1){
      Ans=N+1;
    }else if(A.at(0)==1||N==0&&sum>1){
      Ans=-1;
    }else{
      Ans=1;
      value.at(0).at(2)=1;
      for(int i=0;i<N;i++){
          sum-=A.at(i+1);
          line=value.at(i).at(1)+value.at(i).at(2)*2;
          Ans+=line;
          amount=line-A.at(i+1);
          if(amount<0){
            flag=1;
            Ans=-1;
            break;
          }
          if(amount*2<=sum){
           if(amount==0&&sum!=0){
             flag=1;
             break;
          }
            value.at(i+1).at(2)=amount;
          }else if(amount<=sum){             
            value.at(i+1).at(2)=sum-amount;
            value.at(i+1).at(1)=amount*2-sum;
          }else{
            flag=1;
            Ans=-1;
            break;
          }
      }
    if(flag==1){
      Ans=-1;
    }
    }
 
    cout<<Ans<<endl;
 
 
 
}