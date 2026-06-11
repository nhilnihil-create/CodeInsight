
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S,T,U;
    int A,B;
    cin>>S>>T;
    cin>>A>>B;
    cin>>U;
    
  if(S.length()>=1&&S.length()<=10&&T.length()>=1&&T.length()<=10&&S!=T&&(U==T||U==S)&&A<=10&&A>=1&&B<=10&&B>=1){
    if(U==S){
        A--;
    }
    if(U==T){
        B--;
    }
    cout<<A<<" "<<B;
}
   return 0;
}