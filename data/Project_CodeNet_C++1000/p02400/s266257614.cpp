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
 
 using namespace std;
 
 const double pi=3.1415926535897932384626;
 
 int main()
 {
   double r;
   cin>>r;
   double S=1.0000000000000*pi*r*r;
   double C=2.0000000000000000*pi*r;
   printf("%.6lf %.6lf\n",S,C);
   //while(1);
   return 0;
 }
 
 