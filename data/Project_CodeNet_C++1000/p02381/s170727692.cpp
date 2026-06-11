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
 
 int main()
 {
   int n;
   int arr[1000+5];
   while(cin>>n&&n)
   {
     double sum=0;
     double sum2=0;
     for(int i=0;i<n;i++)
     { 
       cin>>arr[i];
       sum+=arr[i];
     }        
     double average=sum/n;
     for(int i=0;i<n;i++)
     {
       sum2+=pow(arr[i]-average,2);          
     }
     double result=sqrt(sum2/n);
     printf("%.8lf\n",result);
   }
   //while(1);
   return 0;
 }