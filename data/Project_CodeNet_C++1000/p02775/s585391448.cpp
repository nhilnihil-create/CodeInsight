#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
  cin>>s;
  int N=s.size();
  vector<int>A(N);
  for(int i=0;i<N;i++){
  char c=s.at(i); int a=c-'0';
    A.at(i)=a;
  }vector<int>U(N);
  vector<int>D(N);
  U.at(0)=min(11-(A.at(0)+1),A.at(0)+1);
  D.at(0)=min(11-A.at(0),A.at(0));
  for(int i=1;i<N;i++){
  if(A.at(i)!=9 && A.at(i)!=0){
  U.at(i)=min(10-(A.at(i)+1)+U.at(i-1),A.at(i)+1+D.at(i-1));
    D.at(i)=min(10-A.at(i)+U.at(i-1),A.at(i)+D.at(i-1));
  }else if(A.at(i)==0){
  U.at(i)=min(9+U.at(i-1),1+D.at(i-1));
      D.at(i)=D.at(i-1);        
  
  }else{
  U.at(i)=U.at(i-1);
      D.at(i)=min(1+U.at(i-1),9+D.at(i-1));       
  }
  
  
  }cout<<D.at(N-1)<<endl;
   return 0;
}
