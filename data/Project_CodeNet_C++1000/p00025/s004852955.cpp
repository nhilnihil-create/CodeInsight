 
 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<math.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 
 using namespace std;
 
 double abs(double x)
 {
   if(x<0) return -x;
   else return x;       
 }
  
 int main()
 {
   int a[4],b[4];
   int hit,blow;
   while(cin>>a[0])
   {
     hit=blow=0;
     for(int i=1;i<4;i++) cin>>a[i];
     for(int i=0;i<4;i++) cin>>b[i];
     for(int i=0;i<4;i++) if(a[i]==b[i]) hit++;
     for(int i=0;i<4;i++)
     {
       for(int j=0;j<4;j++)
       {
         if(j==i) j++;
         if(a[i]==b[j]) blow++;        
       }        
     }
     cout<<hit<<" "<<blow<<endl;
   }
   //while(1);      
   return 0;    
 }