#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string T;
  cin >> T;
  int P = 0, D = 0, X = 0;
  
  for (int i; i < T.size(); i++) 
  {
    
    if (T.at(i) == '?')
    {
      
      if (i == 0 || T.at(i - 1) == 'D')
      {
        
        if (i == T.size() - 1)
        {
          T.at(i) = 'D';
        }
         else if (T.at(i + 1) == 'D' || T.at(i + 1) == '?')
         {
           T.at(i) = 'P';
         }
         else
         {
           T.at(i) = 'D';
         }
        
      }
      
      else
      {
        T.at(i) = 'D';
      }
      
    }

    
  }
  
  cout << T << endl;
  
}