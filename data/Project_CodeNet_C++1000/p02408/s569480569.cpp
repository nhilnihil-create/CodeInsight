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
 
 int hash[53]={0};
 
 int main()
 {
   int N;
   cin>>N;
   while(N--)
   {
     char type;
     int num;
     cin>>type>>num;
     if(type=='S') hash[num]++;
     else if(type=='H') hash[num+13]++;
     else if(type=='C') hash[num+26]++;
     else hash[num+39]++;          
   }
   for(int i=1;i<=52;i++)
   {
     if(!hash[i])
     {
       int a=(i-1)/13;
       char kk;
       int b=i%13;
       if(b==0) b=13;
       if(a==0) kk='S';
       else if(a==1) kk='H';
       else if(a==2) kk='C';
       else kk='D';
       cout<<kk<<" "<<b<<endl;           
     }        
   }
   //while(1);
   return 0;
 }
 