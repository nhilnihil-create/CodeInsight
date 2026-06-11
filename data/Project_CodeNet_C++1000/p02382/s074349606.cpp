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
 #include<queue>
 #include<functional>
 #include<utility>
 
 using namespace std;
 
 double abs(double m)
 {
   if(m<0) return -m;
   else return m;       
 }
 
 int main()
 {
   double x[100+2],y[100+2];
   int n;
   double d1,d2,d3,di;
   d1=d2=d3=di=0;
   cin>>n;
   for(int i=0;i<n;i++) cin>>x[i];      
   for(int i=0;i<n;i++) cin>>y[i];
   for(int i=0;i<n;i++)
   {
     d1+=abs(x[i]-y[i]);
     d2+=pow(abs(x[i]-y[i]),2);
     d3+=pow(abs(x[i]-y[i]),3);
     if(abs(x[i]-y[i])>di) di=abs(x[i]-y[i]);        
   }   
   d2=sqrt(d2);
   d3=pow(d3,1.0/3);
   printf("%.6lf\n%.6lf\n%.6lf\n%.6lf\n",d1,d2,d3,di);
   //while(1);
   return 0;
 }