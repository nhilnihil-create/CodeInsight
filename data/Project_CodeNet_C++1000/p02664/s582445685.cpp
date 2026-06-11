#include <bits/stdc++.h>
using namespace std;
 
 
 
int main() {
   
  
   string s;
   cin>>s;
   int i;
   string s1=s;
   string s2=s;
   
   int cnt1=0,cnt2=0,max1=0,max2=0;
   for(i=0;i<s1.length();++i)
      {
          if(s1[i]=='?')
              s1[i]='D';
      }
      
  
    for(i=0;i<s1.length();++i)
     {
         if(s1[i]=='D')
            cnt1++;
            
       else if(i<=s1.length()-2 && s1[i]=='P' && s1[i+1]=='D')    
             cnt2++;
     }
     
    max1=cnt1+cnt2;
    
    cnt1=0;
    cnt2=0;
    
    for(i=0;i<s2.length();++i)
      {
          if(s2[i]=='?')
             {
                if(i==0)
                  {
                      if(s2[i+1]=='D')
                         {
                            s2[i]='P';
                         }
                    
                     else
                       s2[i]='D';
                  }
                 
               else  if(s2[i-1]=='P')
                    s2[i]='D';
                    
                 else
                    s2[i]='P';
                    
             }
             
             
      }
     
      
       
     for(i=0;i<s2.length();++i)
      {
         if(s2[i]=='D')
            cnt1++;
            
       else if(i<=s2.length()-2 && s2[i]=='P' && s2[i+1]=='D')    
             cnt2++;   
      }
      
      max2=cnt1+cnt2;
      
      
      if(max1>=max2)
         cout<<s1;
         
      else
         cout<<s2;
       
     
	return 0;
}
