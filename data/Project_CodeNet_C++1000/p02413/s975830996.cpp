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
 
 int arr[100+5][100+5];

 int main()
 {
   int n,m;
   int sum;
   int sum_total=0;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<m;j++)
     {
       cin>>arr[i][j];
       sum_total+=arr[i][j];        
     }        
   }
   for(int i=0;i<n;i++)
   {
     sum=0;
     for(int j=0;j<m;j++)
     {
       cout<<arr[i][j]<<" ";
       sum+=arr[i][j];        
     }          
     cout<<sum<<endl;
   }
   for(int j=0;j<m;j++)
   {
     sum=0;
     for(int i=0;i<n;i++)
     {
       sum+=arr[i][j];        
     }        
     cout<<sum<<" ";
   }
   cout<<sum_total<<endl;
   //while(1);
   return 0;
 }
 
 
 
 
 