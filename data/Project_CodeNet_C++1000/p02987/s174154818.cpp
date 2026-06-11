#include <iostream>

using namespace std;

int main()
{
  string S;
  cin>>S;
  if(S.length()==4){
    if(S[0]==S[1]&&S[1]==S[2]&&S[2]==S[3]){
       cout<<"No";
    }
    
    else if((S[0]==S[1]||S[0]==S[2]||S[0]==S[3]) && (S[1]==S[0]||S[1]==S[2]||S[1]==S[3]) && (S[2]==S[0]||S[2]==S[1]||S[2]==S[3]) && (S[3]==S[0]||S[3]==S[1]||S[3]==S[2])){
     cout<<"Yes";
    }
    else{
        cout<<"No";
    }
  }
    
    return 0;
}