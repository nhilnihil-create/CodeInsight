#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S;
   cin>>S;
   bool easy=true;
   int len=S.size();
   
   rep(i,len){
       if(i%2==0&&S[i]=='L'){
           easy=false;
           break;
       }
       else if(i%2==1&&S[i]=='R'){
           easy=false;
           break;
       }
   }
   if(easy==true){
       cout<<"Yes"<<endl;
   }
   else{
       cout<<"No"<<endl;
   }
    

}
