
                                 /*Bismillahir Rahmanir Rahim*/


#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define ll long long int
#define dd double
using namespace std;
#define M 1000001
ll ara[M];

void sieve()
   {
      int i, j, root;
      for(i = 2; i < 1000001; i++) {
            ara[i] = 1;
         }
   root = sqrt(1000001);

      for(i = 2; i <= root; i++) {
   if(ara[i] == 1) {
for(j = 2; i * j <= 1000001; j++) {
ara[i * j] = 0;
}



}
      }
   }

int main()
{
   ll t,n,i,j,x,a,b,y;
  
   
      sieve();
      cin>>n;
     
      if(ara[n]==1)
      cout<<n<<endl;
      else{
         for(i=n+1;;i++)
         {
            if (ara[i]==1)
            {
            cout<<i<<endl;
               break;
            }
         
      }
      
    
   }

  
   
  

}

//Apna Time Aayega :)