#include <bits/stdc++.h>
using namespace std;


int main(){
   char S[11],T[11],U[11];
   int a,b;
   cin>>S>>T>>a>>b>>U;
   if(strlen(S)==strlen(U)){
   for(int i=0;i<strlen(U);i++){
       if(S[i]!=U[i]){b--;break;}
       if(i==strlen(U)-1)a--;
   }
   }
   else b--;
   printf("%d %d\n",a,b);
}