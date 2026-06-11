#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin>>N;
  int A =(int)N.size();
  if(N.at(A-1)=='3'){
    cout<<"bon"<<endl;
  }else if(N.at(A-1)=='0'||N.at(A-1)=='1'||N.at(A-1)=='6'||N.at(A-1)=='8'){
    cout<<"pon"<<endl;
  }else{
    cout<<"hon"<<endl;
  }
}
  