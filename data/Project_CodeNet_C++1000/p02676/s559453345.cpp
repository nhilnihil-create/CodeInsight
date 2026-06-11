#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main(){
  int K;
  cin >> K;
  string S;
  cin >> S;
  /*
  int U = S.length();
  cout << U << endl;
  */
  
  if(K>=S.length()){
    cout << S << endl;
  }else{
    for(int i=0;i<K;i++){
      cout << S.at(i);
    }
    cout << "...";
  }
  
  cout << endl;
  
}