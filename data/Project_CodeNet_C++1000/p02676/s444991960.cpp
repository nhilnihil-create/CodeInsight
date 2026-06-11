#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

  int k;
  cin >> k;
  string s;
  cin.ignore();
  getline(cin,s);
  
    if(s.size() <= k){
      cout << s;
    }else{
      for(int i=0; i < k; i++){
          cout << s[i];
      }
      cout << "...";
  }
 
  
  return 0;
}