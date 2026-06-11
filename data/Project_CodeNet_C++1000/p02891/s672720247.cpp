#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  long long K;
  cin>>S;
  cin>>K;
  vector <int> a(100,0);
  long long ans=0;
  long long serial=0;
  long long temp=0;
  int on=0;
  
  //全部同じか　※　要検討
  bool flag=1;
  for(int i=1;i<S.length();i++){
    if(S.at(i)!=S.at(0)){
      flag=0;
    }
  }
  if(flag){
    cout<<S.length()*K/2<<endl;
    return 0;
  }
  
  on=0;
  temp=1;
  for(int i=0;i<S.length()-1;i++){
    if(S.at(i)==S.at(i+1)){
      temp++;
      on=1;
    }
    else if(on==1){
      serial=serial+temp/2;
      temp=1;
      on=0;
    }
  }
  if(on==1){
    serial=serial+temp/2;
  }
  
    //Sの最初としっぽが別の場合
  if(S.at(0)!=S.at(S.length()-1)){
    //cout<<"$"<<serial<<endl;
    cout<<serial*K<<endl;
    return 0;
  }

  long long temp1=1;//冒頭の連続文字数
  for(int i=0;i<S.length()-1;i++){
    if(S.at(i+1)==S.at(0)){
        temp1++;
    }
    else break;
  }
  
  long long temp2=0;//末尾の連続文字数
  for(int i=S.length()-1;i>-1;i--){
    if(S.at(i)==S.at(S.length()-1)){
      temp2++;
    }
    else break;
  }
  
  //cout<<serial<<" "<<temp1<<" "<<temp2<<" "<<endl;
  cout<<setprecision(20)<<serial*K-(temp1/2+temp2/2-(temp1+temp2)/2)*(K-1);
  return 0;
}
