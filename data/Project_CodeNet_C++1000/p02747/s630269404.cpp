#include<bits/stdc++.h>
using namespace std;

int main(void){
   string S;
   cin>>S;
   if(S.size()%2==1){
      cout<<"No"<<endl;
      return 0;
   }
   bool flag=true;
   for(int i=0;i<S.size();i++){
      if((i%2==0&&S[i]!='h')||(i%2==1&&S[i]!='i')){
         flag=false;
         break;
      }
   }
   if(flag) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}
