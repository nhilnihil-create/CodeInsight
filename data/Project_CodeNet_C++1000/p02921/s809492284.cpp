#include<iostream>
using namespace std;
int main()
{
      char S[3] , T[3];
      int count =0 ;
      for(int i =0 ; i<3 ; i++)
      { 
           cin>>S[i];
      }
        for(int i =0 ; i<3 ; i++)
      { 
           cin>>T[i];
      }
      
      for(int j=0 ; j<3; j++)
      { 
           if(S[j]==T[j])
           {
                count++;
                
           }
}
cout<<count;
return 0;
} 
