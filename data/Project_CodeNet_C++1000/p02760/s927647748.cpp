#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> A(9);
  for(int i=0; i<9; i++){
    cin>>A.at(i);
  }
  int N;
  cin>>N;
  vector<int> b(N);
  for(int i=0; i<N; i++){
    cin>>b.at(i);
  }
  vector<bool> c(9,false);
  for(int i=0; i<N; i++){
    for(int j=0; j<9; j++){
      if(b.at(i)==A.at(j)){
        c.at(j)=true;
      }
    }
  }
  if(c.at(0)==true&&c.at(1)==true&&c.at(2)==true){
    cout<<"Yes"<<endl;
  }
  else if(c.at(3)==true&&c.at(4)==true&&c.at(5)==true){
    cout<<"Yes"<<endl;
  }
  else if(c.at(6)==true&&c.at(7)==true&&c.at(8)==true){
    cout<<"Yes"<<endl;
  }
  else if(c.at(0)==true&&c.at(3)==true&&c.at(6)==true){
    cout<<"Yes"<<endl;
  }
  else if(c.at(1)==true&&c.at(4)==true&&c.at(7)==true){
    cout<<"Yes"<<endl;
  }
  else if(c.at(2)==true&&c.at(5)==true&&c.at(8)==true){
    cout<<"Yes"<<endl;
  }
  else if(c.at(0)==true&&c.at(4)==true&&c.at(8)==true){
    cout<<"Yes"<<endl;
  }
  else if(c.at(2)==true&&c.at(4)==true&&c.at(6)==true){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}