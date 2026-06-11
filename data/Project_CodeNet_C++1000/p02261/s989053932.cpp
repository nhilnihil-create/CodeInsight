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
 
 int arr[36+5];
 string str[36+5];
 
 int arr2[36+5];
 string str2[36+5];
 string str3[36+5];
 //string str4[36+5];

 int main()
 {
   int N;
   cin>>N;
   for(int i=0;i<N;i++) cin>>str[i];
   for(int i=0;i<N;i++) arr[i]=(str[i].at(1)-'0');
   for(int i=0;i<N;i++) str3[i]=str[i].at(0);
   for(int i=0;i<N;i++) str2[i]=str[i];
   for(int i=0;i<N;i++) arr2[i]=arr[i];
   for(int i=0;i<N;i++)
   {
     for(int j=N-1;j>=i+1;j--)
     {
       if(arr[j]<arr[j-1])
       {
         swap(arr[j],arr[j-1]);
         swap(str[j],str[j-1]);                   
       }        
     }        
   }
   bool flag=true;
   bool flag2=true;
   for(int i=0;i<N-1;i++) cout<<str[i]<<" ";
   cout<<str[N-1];
   cout<<endl;    
   cout<<"Stable"<<endl;
   //else cout<<"Not Stable"<<endl;
   for(int i=0;i<N;i++)
   {
     int mini=i;
     for(int j=i;j<N;j++)
     {
       if(arr2[j]<arr2[mini])
       {
         mini=j;                     
       }        
     }        
     swap(arr2[i],arr2[mini]);
     swap(str2[i],str2[mini]);
   } 
   for(int i=0;i<N-1;i++) cout<<str2[i]<<" ";
   cout<<str2[N-1];
   cout<<endl;
   for(int i=0;i<N;i++)
   {
     if(str2[i][0]!=str[i][0])
     {
       flag2=false;
       break;                                  
     }          
   }
   if(flag2) cout<<"Stable"<<endl;
   else cout<<"Not stable"<<endl;
   //while(1);
   return 0;
 }
 
 