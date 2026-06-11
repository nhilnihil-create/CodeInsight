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
 
 int arr[100+5];
 int n,sum;
 int count1;
 
 void dfs(int i,int x,int m)
 {
   if(x>sum) return;
   if((i==n))
   {
     //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
     //cout<<endl;
     if(sum==x&&m==3)
     {
       count1++;
       //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
       //cout<<endl;
     }
     return;            
   }
   dfs(i+1,x+arr[i],m+1);
   dfs(i+1,x,m);    
   return;
 }

 int main()
 {
   while(cin>>n>>sum&&(n||sum))
   {
     count1=0;
     for(int i=0;i<n;i++) arr[i]=i+1;
     for(int i=0;i<n;i++)
     {
       for(int j=i+1;j<n;j++)
       {
         for(int k=j+1;k<n;k++)
         {
           if((arr[i]+arr[j]+arr[k])==sum) count1++;        
         }        
       }        
     }                    
     cout<<count1<<endl;
   }
   //while(1);
   return 0;
 }
 