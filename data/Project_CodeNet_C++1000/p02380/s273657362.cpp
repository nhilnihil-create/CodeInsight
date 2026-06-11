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
 
 const double PI=3.14159265359;
 
 int main()
 {
   double a,b,c,theta;
   cin>>a>>b>>theta;
   c=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(theta/180*PI));
   double s=1.0/2*a*b*sin(theta/180*PI);
   double C=a+b+c;
   double h=2*s/a;
   printf("%.8lf\n%.8lf\n%.8lf\n",s,C,h);
   //while(1);
   return 0;
 }