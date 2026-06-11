#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  long long temp;
  queue<long long>Q;
  for(int i=1;i<=9;i++){
    Q.emplace(i);
  }
  for(long long i=1;i<=N;i++){
    temp=Q.front();
    //cout<<temp<<endl;
    if(temp%10 !=0){
      Q.emplace(temp*10+temp%10-1);
    }
    Q.emplace(temp*10+temp%10);
    if(temp%10 !=9){
      Q.emplace(temp*10+temp%10+1);
    }
    Q.pop();
  }
  cout<<setprecision(20)<<temp<<endl;
  return 0;
}
