#include <bits/stdc++.h>
using namespace std;

int compare(string s){
  int sum=0;
  for(int i=0;i<(int)s.size()/2;i++){
    if(s.at(i)!=s.at(s.size()-1-i)){
      sum++;
      break;
    }
  }
  return sum;
}
      
int main(){
 string S;
  cin>>S;
  int a;
  int N =(int)S.size();
  a=compare(S);
 int b=0;
  for(int i=0;i<N/4;i++){
    if(S.at(i)!=S.at(N/2-1-i)){
      b++;
      break;
    }
  }
  for(int i=0;i<N/4;i++){
    if(S.at((N+1)/2+i)!=S.at(N-1-i)){
      b++;
      break;
    }
  }
  if(a+b==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
  