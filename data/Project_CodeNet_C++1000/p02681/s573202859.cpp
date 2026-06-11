#include<bits/stdc++.h>


using namespace std;

int main()
{
  int i = 0;
  string S,T; 
  cin >> S >> T;



    for(i = 0; i <= S.length()-1; i++){
      if(S[i] == T[i])
      {
        continue;
      }

      else
      {
        cout << "No";
        exit(0);
      }
    }

    cout << "Yes";
}
    
  