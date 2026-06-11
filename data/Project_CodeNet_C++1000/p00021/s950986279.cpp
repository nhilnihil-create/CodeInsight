 
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
   double x1,y1,x2,y2,x3,y3,x4,y4;
   int n;
   cin>>n;
   while(n--)
   {
     cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    
       double k1=(y2-y1)/(x2-x1);
       double k2=(y4-y3)/(x4-x3);
       double judge=(x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);
       if((abs(judge)<0.000000000001)) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;     
           
   }
   //while(1);      
   return 0;    
 }