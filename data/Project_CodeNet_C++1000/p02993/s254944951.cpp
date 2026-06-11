#include <iostream>

using namespace std;

int main()
{
  string S;
  cin>>S;
  if(S.length()==4){
      if(S[0]==S[1]||S[1]==S[2]||S[2]==S[3]){
          cout<<"Bad";
      }
      else{
          cout<<"Good";
      }
  }
    
    return 0;
}