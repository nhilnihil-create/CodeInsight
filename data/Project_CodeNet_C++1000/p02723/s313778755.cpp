#include <bits/stdc++.h>

using namespace std;

int main()
{
   string S;
   cin>>S;
   if(S.length()==6){
       if(S[2]==S[3]&&S[4]==S[5]){
           cout<<"Yes";
       }
       else{
           cout<<"No";
       }
   }
}