#include <bits/stdc++.h>

using namespace std;

int main()
{
  int m1,d1,m2,d2;
  cin>>m1>>d1>>m2>>d2;
  
  if(m1==8)
  {
      if(d1==30 && m2==9 && d2==1)
         printf("1");
         
      else
        printf("0");
  }
  
  else if(m1==2)
    {
        if(d1==28 && d2==1 && m2==3)
           printf("1");
           
        else
           printf("0");
    }
    
  else if(m1<8 && m1!=2)
   {
       if(m1%2!=0)
       {
           if(d1==31 && d2==1 && m2==m1+1)
              printf("1");
              
            else
               printf("0");
       }
       
       else
         {
             if(d1==30 && d2==1 && m2==m1+1)
                printf("1");
                
             else
               printf("0");
         }
          
   }
   
   else
    {
        if(m1%2!=0)
         {
             if(d1==30 && d2==1 && m2==m1+1)
                printf("1");
                
             else
               printf("0");
         }
         
         else
           {
               if(d1==31 && d2==1 && ((m2==m1+1) ||(m1==12 && m2==1)))
                  printf("1");
                  
                else
                  printf("0");
                  
           }
    }
}