#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin>>S;
  //cout<<S.at(0)<<S.at(1)<<S.at(2)<<endl;
  int N=S.size();//cout<<N<<endl;
  vector<int>a(N+10);
  //for(int i=0;i<N+1;i++){cout<<a.at(i)<<endl;}
   for(int i=0;i<N;i++){
    if(S.at(i)=='<'){a.at(i+1)=a.at(i)+1;}
  } //cout<<S.at(N-1)<<endl;
  //for(int i=0;i<N+1;i++){cout<<a.at(i);}cout<<a.size()<<endl;

  for(int i=N-1;i>=0;i--){
    if(S.at(i)=='>'){a.at(i)=max(a.at(i),a.at(i+1)+1);}
  }
  //for(int i=0;i<N+1;i++){cout<<a.at(i);}cout<<endl;
   //for(int i=0;i<N;i++){cout<<a.at(i)<<" ";}//cout<<endl;//
   
  int64_t sum=0;
  for(int i=0;i<N+1;i++){
    sum+=a.at(i);
  }
  cout<<sum<<endl;
  return 0;
}