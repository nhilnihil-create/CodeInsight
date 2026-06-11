#include<iostream>  
  using namespace std;  
  
  int main(){  
      string S;  
      int N;  
      cin >> N >> S;  
      auto size = S.size();  
      for(int i = 0; i < size; i++){  
          S[i] += N;  
          if(S[i] > 'Z') S[i] -= 'Z' - 'A' + 1;
      }  
      cout << S << endl;
      return 0;  
  }